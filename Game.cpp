#include "Game.hpp"
#include <ctime>

Game::Game(){
    // inisialissasi atribut
    gameDirection = 0;
    game = 1;
    round = 1;
    poinTotal = 64;

    // inisialisasi table
    TableCard *buf = new TableCard();
    table = *buf;

    // inisialisasi player
    firstPlayerId = 1;
    urutan.clear();
    for(int i = 1; i <= 7; i++){
        urutan.push_back(i);
    }
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
    // for(int i = 0; i < tumpukan.size();i++){
    //     cout << tumpukan[i].getAngka()<<tumpukan[i].getWarna() << endl;
    // }

    vector<AngkaCard> tablecards;
    for(int i = 0; i<5; i++){
        tablecards.push_back(cards.back());
        cards.pop_back();
    }

    table.setMainDeck(cards);
}

// AngkaCard Game::takeCardTable(){
//     return table.takeCard();
// }

void Game::newRound(){
    // if (InventoryHolder::round == 2){
    //     Array<AbilityCard> L; 
    //     AbilityCard a(1,"Reverse");
    //     AbilityCard b(2, "Re-Roll");
    //     AbilityCard c(3, "Quarter");
    //     AbilityCard d(4, "Reverse Direction");
    //     AbilityCard e(5, "Swap Card");
    //     AbilityCard f(6, "Switch");
    //     AbilityCard g(7, "Abilityless");

    //     L.addfirst(a);
    //     L.addfirst(b);
    //     L.addfirst(c);
    //     L.addfirst(d);
    //     L.addfirst(e);
    //     L.addfirst(f);
    //     L.addfirst(g);

    //     int M = rand()%6;
    //     players.get(0).setAbility(L.get(M));
    //     L.operator-(L.get(M));
    //     M = rand()%5;

    //     players.get(1).setAbility(L.get(M));
    //     L.operator-(L.get(M));
    //     M = rand()%4;

    //     players.get(2).setAbility(L.get(M));
    //     L.operator-(L.get(M));

    //     M = rand()%3;
    //     players.get(3).setAbility(L.get(M));
    //     L.operator-(L.get(M));

    //     M = rand()%2;
    //     players.get(4).setAbility(L.get(M));
    //     L.operator-(L.get(M));

    //     M = rand()%1;
    //     players.get(5).setAbility(L.get(M));
    //     L.operator-(L.get(M));

    //     M = 0;
    //     players.get(6).setAbility(L.get(M));
    //     L.operator-(L.get(M));
    // }
    cout << "Method new round" << endl;
    if(round == 2){
        cout << "Method membagi ability" << endl;
    }
}

void Game::showPoin(){
    cout << "Poin pemain saat ini: " << endl;
    for(int i = 0; i < players.size(); i++){
        cout << i+1 << ". <p" << i+1 << "> memiliki poin " << players[i]->getPoin() << endl;
    }
}

void Game::commandParser(int i, string command){
    if (command == "next"){
        cout << "Method next (belum diimplementasi)" << endl;
    }
    else if(command == "reroll"){
        cout << "Method reroll (belum diimplementasi)" << endl;
    }
    else if(command == "double"){
        cout << "Method double (belum diimplementasi)" << endl;
    }
    else if(command == "quadruple"){
        cout << "Method quadruple (belum diimplementasi)" << endl;
    }
    else if(command == "half"){
        cout << "Method half (belum diimplementasi)" << endl;
    }
    else if(command == "quarter"){
        cout << "Method quarter (belum diimplementasi)" << endl;
    }
    else if(command == "reverse"){
        cout << "Method reverse (belum diimplementasi)" << endl;
    }
    else if(command == "swap"){
        cout << "Method swap (belum diimplementasi)" << endl;
    }
    else if (command == "switch"){
        cout << "Method switch (belum diimplementasi)" << endl;
    }
    else if(command == "abilityless"){
        cout << "Method abilityless (belum diimplementasi)" << endl;
    }else if(command == "value"){
        Kombo k(players[i]->getCards(), table.getCards());
        cout <<k.value(100)<<endl;
    }
    else{
        /* exception */
        cout << "salah command mas" << endl;
    }
}

void Game::start(){
    cout << "START" << endl;
    // isi table
    resetNewGame();

    setTable();
    vector<pair<int, Kombo>> kombo;
    players.clear();
    for(int i = 0; i < 7; i++){
        Player *p = new Player(i);
        AngkaCard c1 = takeCard();
        AngkaCard c2 = takeCard();
        (*p).newCard(c1,c2);
        players.push_back(p);
    }
    while (!endGame()){
        while (round <= 6){
            cout << "Sekarang adalah permainan ke " << game << " ronde ke " << round << "." << endl;
            cout << "Putaran permainan: ";
            showUrutan();
            // iterasi command tiap pemain
            int i = 0;
            string inp;
            while(i < 7){
                if (round == 6){
                    showMain(5);
                }
                else{
                    showMain(round);
                }
                cout << endl;
                cout << "Giliran pemain <p" << urutan[i] << "> !" << endl;
                cout << "Kartu yang anda miliki: " << endl;
                players[urutan[i]-1]->displayCards();
                cout << "Masukkan command Anda: ";
                cin >> inp;
                // lakukan command, jangan lupa exception
                // kalau ada efek reverse sekalian panggil reverseEffect(int urutan[i])
                commandParser(urutan[i]-1, inp);
                i++;
            }
            // atur urutan lagi
            urutan.clear();
            int idd;
            firstPlayerId = ((firstPlayerId+1)%7);
            if(gameDirection == 0){
                for(int i = 0; i < 7; i++){
                    idd = (firstPlayerId+i) % 7;
                    if(idd == 0){
                        idd = 7;
                    }
                    urutan.push_back(idd);
                }
            }
            else{
                for(int i = 7; i <= 0; i--){
                    idd = (firstPlayerId+i) % 7;
                    if(idd == 0){
                        idd = 7;
                    }
                    urutan.push_back(idd);
                }
            }
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

    int poin[7] = {players[0]->getPoin(), players[1]->getPoin(), players[2]->getPoin(), players[3]->getPoin(), players[4]->getPoin(), players[5]->getPoin(), players[6]->getPoin()};
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


void Game::showUrutan(){
    for(int i = 0; i < urutan.size(); i++){
        cout << "<p" << urutan[i] << "> ";
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

void Game::reverseEffect(int currPlayer){
    vector<int> buff;
    for(int i = 0; i < currPlayer; i++){
        buff.push_back(urutan[i]);
        urutan.erase(urutan.begin());
    }
    while(!urutan.empty()){
        buff.push_back(urutan.size()-1);
        urutan.pop_back();
    }
}

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

template <class T>
void randomizeDeck(vector<T> &vec, int size){
    int index, secondIndex;
    T temp;
    srand((unsigned) time(NULL));
    for(index = 0; index<size; index++){
        secondIndex = rand() % size;
        temp = vec[index];
        vec[index] = vec[secondIndex];
        vec[secondIndex] =  temp;
    }
}

// void Game::testCom(){
//     cout << "START" << endl;
//     // isi table
//     table.resetNewGame();
//     setTable();
//     vector<pair<int,Kombo>> kombo;
//     players.clear();
//     for(int i = 0; i < 7; i++){
//         Player p(i);
//         AngkaCard c1 = takeCardTable();
//         AngkaCard c2 = takeCardTable();
//         p.newCard(c1,c2);
//         players.push_back(p);
//     }
//     while (!endGame()){
//         while (round <= 6){
//             cout << "Sekarang adalah permainan ke " << game << " ronde ke " << round << "." << endl;
//             cout << "Putaran permainan: ";
//             showUrutan();
//             // iterasi command tiap pemain
//             int i = 0;
//             string inp;
//             while(i < 7){
//                 if (round == 6){
//                     showMain(5);
//                 }
//                 else{
//                     showMain(round);
//                 }
//                 cout << endl;
//                 i++;
//             }
//             // atur urutan lagi
//             urutan.clear();
//             int idd;
//             firstPlayerId = ((firstPlayerId+1)%7);
//             if(gameDirection == 0){
//                 for(int i = 0; i < 7; i++){
//                     idd = (firstPlayerId+i) % 7;
//                     if(idd == 0){
//                         idd = 7;
//                     }
//                     urutan.push_back(idd);
//                 }
//             }
//             else{
//                 for(int i = 7; i <= 0; i--){
//                     idd = (firstPlayerId+i) % 7;
//                     if(idd == 0){
//                         idd = 7;
//                     }
//                     urutan.push_back(idd);
//                 }
//             }
//             round++;
//         }
//         // cari pemenang
//         kombo.clear();
//         int limit = 139*9 + 1;
        
        

        

//         for(int i = 0; i < players.size(); i++){
//             Kombo k(players[i].getCard(), table.getMainDeck());
//             pair<int,Kombo> t(k.value(limit), k);
//             kombo.push_back(t);
//             cout<<i+1<<". "<<k.value(limit) << endl;
//         }
        
//         while((kombo[0].first == kombo[1].first)&& (kombo[1].first == kombo[2].first)&&(kombo[2].first == kombo[3].first) && (kombo[3].first == kombo[4].first) && (kombo[4].first == kombo[5].first) && (kombo[5].first == kombo[6].first)){
//             //kasus table card tertinggi
//             limit = kombo[0].first;//renew limit
//             kombo.clear();
//             for(int i = 0; i < players.size(); i++){
//                 Kombo k(players[i].getCard(), table.getMainDeck());
//                 pair<int,Kombo> t(k.value(limit), k);
//                 kombo.push_back(t);
//                 cout<<i+1<<". "<<k.value(limit) << endl;
//             }
//         }
//         ;
        

//         bool found = false;
//         int i = 0;
//         vector<int> winner;

//         for(i = 0;i< 7;i++){
//             if(kombo[i].first == max_element(kombo.begin(), kombo.end(), [](const auto& left, const auto& right){return left.first<right.first;})->first){
//                 winner.push_back(i);
//             }
//         }
//         i=0;
//         int index=0;
//         if(winner.size()>1){
//             bool same = true;
//             while(i<5 && same){
//                 cout<<i;
//                 for(int j = 1;j<winner.size();j++){
//                     if(kombo[winner[index]].second.get(i) > kombo[winner[j]].second.get(i)){
//                         same = false;
//                         cout<<" "<<kombo[winner[index]].second.get(i).valuecard() <<" "<<kombo[winner[j]].second.get(i).valuecard();
//                         cout<<"Exit"<<endl;
                        
//                     }else if(kombo[winner[index]].second.get(i) < kombo[winner[j]].second.get(i)){
//                         same = false;
//                         index = j;
//                         cout<<"Shift"<<endl;
//                     }
//                 }
                    
//                 i++;
//             }
//         }
        
//         cout << "Pemenang pada game ini adalah adalah <p" << winner[index]+1 << "> !" << endl;
//         // berikan poin total pada pemenang
//         players[winner[index]].addPoin(poinTotal);
//         showPoin();
//         poinTotal = 64;
        
//         // reset untuk game berikutnya
//         table.resetNewGame();
//         round = 1;
//         game++;
//         setTable();
//         for(int i = 0; i < players.size(); i++){
//             players[i].resetNewGame();
//             AngkaCard c1 = takeCardTable();
//             AngkaCard c2 = takeCardTable();
//             players[i].newCard(c1,c2);
//         }
//     }

//     int poin[7] = {players[0].getPoin(), players[1].getPoin(), players[2].getPoin(), players[3].getPoin(), players[4].getPoin(), players[5].getPoin(), players[6].getPoin()};
//     bool foundWinner = false;
//     int idWinnerAll;
//     int j = 0;
//     while(j < 7 && !foundWinner){
//         if(*max_element(poin,poin+7) == players[j].getPoin()){
//             foundWinner = true;
//             idWinnerAll = j + 1;
//         }
//     }
//     cout << "Selamat, pemenangnya adalah <p" << idWinnerAll << "> !!" << endl;
// }