#include "Game.hpp"

Commands::Commands(Game* _game){
    game = _game;
    used = false;
    disabled = false;
    player = game->getCurrentPlayer();
    players = game->getPlayers();
}

Next::Next(Game* _game): Commands(_game){}

Reroll::Reroll(Game* _game): Commands(_game){}
void Reroll::action(){
    /* Buang 2 kartu dari tangan */
    /* Ambil 2 kartu baru dari deck*/
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

    AngkaCard c1 = game->takeCard();
    AngkaCard c2 = game->takeCard();

    player->clearCards();

    player->pushCard(c1);
    player->pushCard(c2);
    // *player + c1 + c2;


    cout << "1. " << c1.getAngka() << " " << c1.getWarna() << endl;
    cout << "2. " << c2.getAngka() << " " << c2.getWarna() << endl;
}

Multiply::Multiply(Game* _game, long long _multiplier): Commands(_game), multiplier(_multiplier){}
void Multiply::action(){
    long long newPoin = multiplier*game->getPoinTotal();
    game->setPoinTotal(newPoin);

    string prompt;
    if(multiplier==2) prompt = "DOUBLE!";
    else if(multiplier==4)prompt = "QUADRUPLE";

    cout << "<p"<< player->getId() << "> melakukan "<< prompt <<" Poin hadiah naik menjadi " << game->getPoinTotal() << "!" << endl;
}
Double::Double(Game* _game): Multiply(_game, 2){}
Quadruple::Quadruple(Game* _game): Multiply(_game, 4){}

Divide::Divide(Game* _game, int _divisor): Commands(_game), divisor(_divisor){}
void Divide::action(){
    if(game->getPoinTotal() == 1) throw "Poin hadiah sudah bernilai 1. Poin hadiah tidak berubah. Giliran berlanjut!";

    game->setPoinTotal(game->getPoinTotal()/divisor);
    if(game->getPoinTotal()==0) game->setPoinTotal(1);

    string prompt;
    if(divisor==2) prompt = "HALF!";
    else if(divisor==4)prompt = "QUARTER";

    cout << "<p" << player->getId() << "> melakukan "<< prompt <<" Poin hadiah turun menjadi " << game->getPoinTotal() << "!" << endl;
}
Half::Half(Game* _game): Divide(_game, 2){}
Quarter::Quarter(Game* _game): Divide(_game, 4){}

Reverse::Reverse(Game* _game): Commands(_game){}
void Reverse::action(){
    cout << player->getId() << "melakukan REVERSE!" << endl;
    cout << "(sisa) urutan eksekusi giliran ini : "; /* Urutannya */ 
    game->showUrutan(game->getCurrentTurn());

    game->changeDirection();
    game->resetCurrentTurn();
    cout << "urutan eksekusi giliran selanjutnya : "; /* Urutan baru */
    game->showUrutan();
}

Swap::Swap(Game* _game): Commands(_game){}
void Swap::action(){
    cout << player->getId() << "melakukan SWAP!" << endl;

    cout<<"Pilih pemain yang mau kamu tukar kartunya:"<<endl;
    Player* playerA = game->chooseOtherPlayer();

    vector<Player*> tempPlayers;
    for(Player* player:players){
        if(player->getId() != playerA->getId())tempPlayers.push_back(player);
    }

    cout<<"Pilih pemain lain yang mau kamu tukar kartunya:"<<endl;
    Player* playerB = game->chooseOtherPlayer(tempPlayers);

    AngkaCard& c1 = chooseCard(playerA);
    // cout<<c1.getAngka()<<c1.getWarna()<<endl;;
    AngkaCard& c2 = chooseCard(playerB);
    // cout<<c2.getAngka()<<c2.getWarna()<<endl;;

    playerA->pushCard(c2);
    playerB->pushCard(c1);
    // *playerA + c2;
    // *playerB + c1;
}
AngkaCard& Swap::chooseCard(Player* target){
    cout<<"Pilih kartu kanan/kiri milik pemain_"<<target->getId()<<endl;
    cout<<"1. Kanan"<<endl<<"2. Kiri"<<endl;
    int temp;
    cout<<"Kartu pilihan: ";
    cin>>temp;

    if(temp!=1 && temp!=2) throw "Masukan tidak valid";

    return target->takeCard(temp-1);
}

Switch::Switch(Game* _game): Commands(_game){}
void Switch::action(){
    // cout<<"<pemain_"<<player->getId()<<"> melakukan SWITCH!"<<endl;
    // cout<<"Kartumu sekarang adalah:"<<endl;
    // player->displayCards();

    // cout<<"Pilih pemain yang mau kamu tukar kartunya"<<endl;
    // players.erase(find(players.begin(), players.end(), player));
    // Player* other = chooseOtherPlayer();

    // // AngkaCard c1, c2, c3, c4;
    // AngkaCard c1 = other->takeCard();
    // AngkaCard c2 = other->takeCard();
    // AngkaCard c3 = player->takeCard();
    // AngkaCard c4 = player->takeCard();

    // *player + c1 + c2;
    // *other + c3 + c4;

    // cout<<"Kedua kartumu berhasil ditukar dengan kartu milik <pemain_"<<other->getId()<<">!"<<endl;
    // cout<<"Kartumu sekarang adalah:"<<endl;
    // player->displayCards();
}

Abilityless::Abilityless(Game* _game): Commands(_game){}
void Abilityless::action(){
    cout<<"<pemain_"<<player->getId()<<"> melakukan ABILITYLESS!"<<endl;
    cout<<"Pilih pemain yang abilitynya mau dimatikan"<<endl;
    Player* other = game->chooseOtherPlayer();
    map<string, Commands*> actions = other->getPlayerActions();

    string keys[] = {"REROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH"};
    for(string key : keys){
        if(actions.find(key) != actions.end()){
            actions[key]->disable();
        }
    }
}
Game::Game(){
    // inisialissasi atribut
    gameDirection = 1;
    game = 1;
    round = 1;
    poinTotal = 64;
    currentTurn = 0;

    // inisialisasi table
    TableCard *buf = new TableCard();
    table = *buf;

    // inisialisasi player
    firstPlayerId = 0;
    // urutan.clear();
    // for(int i = 1; i <= 7; i++){
    //     urutan.push_back(i);
    // }

    Utils::shuffle(abilities);
}

void Game::randomTableDeck(){
    this->clearCards();
    /* Isi tumpukan kartu */
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Merah");
        pushCard(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Hijau");
        pushCard(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Kuning");
        pushCard(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Biru");
        pushCard(c);
    }

    Utils::shuffle(cards);
    // for(int i = 0; i < tumpukan.size();i++){
    //     cout << tumpukan[i].getAngka()<<tumpukan[i].getWarna() << endl;
    // }

    vector<AngkaCard> tablecards;
    for(int i = 0; i<5; i++){
        tablecards.push_back(cards.back());
        cards.pop_back();
    }

    table.setMainDeck(tablecards);
}

// AngkaCard Game::takeCardTable(){
//     return table.takeCard();
// }

vector<Player*> Game::getPlayers(){
    return players;
}

Player* Game::getCurrentPlayer(){
    return currentPlayer;
}

Player* Game::chooseOtherPlayer(vector<Player*> _players){
    int i = 1;
    vector<Player*> tempPlayers;

    for(Player* player : _players){
        if(player->getId() == currentPlayer->getId()) continue;
        else tempPlayers.push_back(player);
        cout<<i<<". <pemain_"<<player->getId()<<">"<<endl;
        i++;
    }
    int temp;
    
    cout<<"Pemain pilihan: ";
    cin>>temp;
    if(temp<=0 || temp>_players.size()) throw "Batas";
    cout<<"chosen "<<tempPlayers[temp-1]->getId()<<endl;
    return tempPlayers[temp-1];
}


Player* Game::chooseOtherPlayer(){
    return chooseOtherPlayer(players);
}

void Game::showPoin(){
    cout << "Poin pemain saat ini: " << endl;
    for(int i = 0; i < players.size(); i++){
        cout << i+1 << ". <p" << i+1 << "> memiliki poin " << players[i]->getPoin() << endl;
    }
}

void Game::commandParser(string command){
    command = Utils::toupper(command);
    vector<string> availableCommands = {"NEXT", "HALF", "DOUBLE", "REROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"};
    if (find(availableCommands.begin(), availableCommands.end(), command) != availableCommands.end()){
        currentPlayer->action(command);
    }
    // }else if(command == "value"){
    //     Kombo k(players[i]->getCards(), table.getCards());
    //     cout <<k.value(100)<<endl;
    // }
    // else{
    //     /* exception */
    //     cout << "salah command mas" << endl;
    // }
}

void Game::start(){
    cout << "START" << endl;
    // isi table
    resetNewGame();

    setTable();
    vector<pair<int, Kombo>> kombo;
    players.clear();
    for(int i = 1; i <= 7; i++){
        Player *p = new Player(i);
        AngkaCard c1 = takeCard();
        AngkaCard c2 = takeCard();
        (*p).newCard(c1,c2);

        players.push_back(p);
    }
    for(int i=0; i<7; i++){
        currentPlayer = players[i];

        assignCommand("NEXT", *currentPlayer);
        assignCommand("HALF", *currentPlayer);
        assignCommand("DOUBLE", *currentPlayer);
    }
    while (!endGame()){
        while (round <= 6){
            cout << "Sekarang adalah permainan ke " << game << " ronde ke " << round << "." << endl;
            cout << "Putaran permainan: ";
            showUrutan();
            // iterasi command tiap pemain
            int i = 0;            
            string inp;

            while(i<7){
                players[i]->newTurn();
                i++;
            }
            i = 0;
            resetCurrentTurn();
            while(i < 7){
                currentPlayer = getPlayerAtTurn(currentTurn);
                while(currentPlayer->hasDoneTurn()){
                    currentPlayer = getPlayerAtTurn(currentTurn);
                    currentTurn++;
                }

                if (round == 6){
                    showMain(5);
                }
                else{
                    showMain(round);
                }
                cout << endl;
                cout << "Giliran pemain <p" << currentPlayer->getId() << "> !" << endl;
                cout << "Kartu yang anda miliki: " << endl;
                currentPlayer->displayCards();
                if(round == 2){
                    assignAbility(*currentPlayer);
                    cout << "Kamu mendapatkan ability "<<currentPlayer->getAbility()<<endl;
                }
                if(round >2){
                    cout<<"Ability: "<<currentPlayer->getAbility();
                    if(currentPlayer->getPlayerActions()[currentPlayer->getAbility()]->isUsed()){
                        cout<<" (USED)";
                    }
                    cout<<endl;
                }

                try{
                    cout << "Masukkan command Anda: ";
                    cin >> inp;
                    // lakukan command, jangan lupa exception
                    // kalau ada efek reverse sekalian panggil reverseEffect(int urutan[i])
                    commandParser(inp);
                }
                catch(char const* e){
                    cout << e << endl;
                }
                catch(const exception& e){
                    cout<<e.what()<<endl;
                }

                currentPlayer->endTurn();
                i++;
            }
            // atur urutan lagi
            firstPlayerId = ((firstPlayerId+gameDirection+7)%7);
            
            round++;
        }
        // cari pemenang
        kombo.clear();
        int limit = 139*9 + 1;
        
        

        

        for(int i = 0; i < players.size(); i++){
            Kombo k(players[i]->getCards(), table.getCards());
            pair<int,Kombo> t(k.value(limit), k);
            kombo.push_back(t);
            cout<<i+1<<". "<<k.value(limit) << endl;
        }
        
        while((kombo[0].first == kombo[1].first)&& (kombo[1].first == kombo[2].first)&&(kombo[2].first == kombo[3].first) && (kombo[3].first == kombo[4].first) && (kombo[4].first == kombo[5].first) && (kombo[5].first == kombo[6].first)){
            //kasus table card tertinggi
            limit = kombo[0].first;//renew limit
            kombo.clear();
            for(int i = 0; i < players.size(); i++){
                Kombo k(players[i]->getCards(), table.getCards());
                pair<int,Kombo> t(k.value(limit), k);
                kombo.push_back(t);
                cout<<i+1<<". "<<k.value(limit) << endl;
            }
        }
        ;
        

        bool found = false;
        int i = 0;
        vector<int> winner;

        for(i = 0;i< 7;i++){
            if(kombo[i].first == max_element(kombo.begin(), kombo.end(), [](const auto& left, const auto& right){return left.first<right.first;})->first){
                winner.push_back(i);
            }
        }
        i=0;
        int index=0;
        if(winner.size()>1){
            bool same = true;
            while(i<5 && same){
                cout<<i;
                for(int j = 1;j<winner.size();j++){
                    if(kombo[winner[index]].second.get(i) > kombo[winner[j]].second.get(i)){
                        same = false;
                        cout<<" "<<kombo[winner[index]].second.get(i).valuecard() <<" "<<kombo[winner[j]].second.get(i).valuecard();
                        cout<<"Exit"<<endl;
                        
                    }else if(kombo[winner[index]].second.get(i) < kombo[winner[j]].second.get(i)){
                        same = false;
                        index = j;
                        cout<<"Shift"<<endl;
                    }
                }
                    
                i++;
            }
        }
        
        cout << "Pemenang pada game ini adalah adalah <p" << winner[index]+1 << "> !" << endl;
        // berikan poin total pada pemenang
        players[winner[index]]->addPoin(poinTotal);
        showPoin();
        poinTotal = 64;

        // reset untuk game berikutnya
        resetNewGame();
        round = 1;
        game++;
        setTable();
        for(int i = 0; i < players.size(); i++){
            players[i]->clearCards();
            AngkaCard c1 = takeCard();
            AngkaCard c2 = takeCard();
            players[i]->newCard(c1,c2);
        }
    }

    long long poin[7] = {players[0]->getPoin(), players[1]->getPoin(), players[2]->getPoin(), players[3]->getPoin(), players[4]->getPoin(), players[5]->getPoin(), players[6]->getPoin()};
    bool foundWinner = false;
    int idWinnerAll;
    int j = 0;
    while(j < 7 && !foundWinner){
        if(*max_element(poin,poin+7) == players[j]->getPoin()){
            foundWinner = true;
            idWinnerAll = j + 1;
        }
    }
    cout << "Selamat, pemenangnya adalah <p" << idWinnerAll << "> !!" << endl;
}

int Game::getIdxOfTurn(int i){
    return (firstPlayerId+i*gameDirection+7)%7;
}

Player* Game::getPlayerAtTurn(int i){
    return players[getIdxOfTurn(i)];
}

void Game::nextTurn(){
    currentTurn = (currentTurn+gameDirection+7)%7;
    currentPlayer = getPlayerAtTurn(currentTurn);
}

void Game::showUrutan(){
    showUrutan(0);
}

void Game::showUrutan(int start){
    int i = start;
    while(i<7){
        cout << "<p" << getIdxOfTurn(i)+1 << ">";
        i++;
    }
    cout << endl;
}

bool Game::endGame(){
    bool end = false;
    int i = 0;
    while(i < players.size() && !end){
        if(players[i]->getPoin() >= pow(2,32)){
            end = true;
        }
        i++;
    }
    return end;
}

void Game::showMain(int N){
    cout << "Kartu pada meja sekarang: " << endl;
    table.showInRound(N);
}

// void Game::reverseEffect(int currPlayer){
//     vector<int> buff;
//     for(int i = 0; i < currPlayer; i++){
//         buff.push_back(urutan[i]);
//         urutan.erase(urutan.begin());
//     }
//     while(!urutan.empty()){
//         buff.push_back(urutan.size()-1);
//         urutan.pop_back();
//     }
// }

void Game::setTable(){
    cout << "Tumpukan kartu pakai randomizer atau file?" << endl;
    cout << "1. Randomizer" << endl << "2. File" << endl;
    bool valid = false;
    char inp;
    while(!valid){
        try{
            cout << "Masukkan pilihan: ";
            cin >> inp;
            if (inp != '1' && inp != '2'){
                throw "Input tidak valid";
            }
            else{
                valid = true;
            }
        }
        catch(string e){
            cout << e << endl;
        }
    }
    cout << endl;
    if (inp == '1'){
        randomTableDeck();
    }
    else{
        cout << "Masukkan nama file: " << endl;
        // exception ....
        string filename;
        readFromFile(filename);
    }
}

void Game::readFromFile(string namaFile){
    InventoryHolder::readFromFile(namaFile);

    vector<AngkaCard> tablecards;
    for(int i = 0; i<5; i++){
        tablecards.push_back(cards.back());
        cards.pop_back();
    }
    table.setMainDeck(tablecards);
}

void Game::resetNewGame(){
    clearCards();
    table.clearCards();
}

void Game::assignCommand(string key, Player& player){
    Commands* command;

    if(key == "NEXT") command = new Next(this);
    if(key == "REROLL") command = new Reroll(this);
    if(key == "DOUBLE") command = new Double(this);
    if(key == "QUADRUPLE") command = new Quadruple(this);
    if(key == "HALF") command = new Half(this);
    if(key == "QUARTER") command = new Quarter(this);
    if(key == "REVERSE") command = new Reverse(this);
    if(key == "SWAP") command = new Swap(this);
    if(key == "SWITCH") command = new Switch(this);
    if(key == "ABILITYLESS") command = new Abilityless(this);

    player.insertPlayerAction(pair<string, Commands*>(key, command));
}

void Game::assignAbility(Player& player){
    string ability = abilities.back();
    abilities.pop_back();

    player.setAbility(ability);
    assignCommand(ability, player);
}

void Game::changeDirection(){
    if(gameDirection==1) gameDirection=-1;
    else if(gameDirection==-1) gameDirection=1;
}

