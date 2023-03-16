#include "Game.hpp"

Game::Game():InventoryHolder(){
    // inisialissasi atribut
    gameDirection = 0;
    game = 1;
    round = 1;
    poinTotal = 64;

    // inisialisasi table
    TableCard *buf = new TableCard();
    table = *buf;

    // inisialisasi player
    players.clear();
    for(int i = 0; i < 7; i++){
        Player p(i);
        AngkaCard c1 = takeCardTable();
        AngkaCard c2 = takeCardTable();
        p.newCard(c1,c2);
    }
    firstPlayerId = 1;
    urutan.clear();
    for(int i = 1; i <= 7; i++){
        urutan.push_back(i);
    }
    cout << "tes" << endl;
}


AngkaCard Game::takeCardTable(){
    return table.takeCard();
}

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
        cout << i+1 << ". <p" << i+1 << "> memiliki poin " << players[i].getPoin() << endl;
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
    }
    else{
        /* exception */
        cout << "salah command mas" << endl;
    }
}

void Game::start(){
    cout << "START" << endl;
    // isi table
    table.resetNewGame();
    setTable();
    vector<double> kombo;

    while (!endGame()){
        setTable();
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
                cout << "Giliran pemain <p" << urutan[i] << "> !" << endl;
                cout << "Kartu yang anda miliki: " << endl;
                players[urutan[i]-1].displayCard();
                cout << "Masukkan command Anda: ";
                // lakukan command, jangan lupa exception
                // kalau ada efek reverse sekalian panggil reverseEffect(int urutan[i])
                commandParser(urutan[i]-1, inp);
                i++;
            }
            // atur urutan lagi
            urutan.clear();
            firstPlayerId = (firstPlayerId+1)%7;
            if(gameDirection == 0){
                for(int i = 0; i < 7; i++){
                    urutan.push_back((firstPlayerId+i) % 7);
                }
            }
            else{
                for(int i = 7; i <= 0; i--){
                    urutan.push_back((firstPlayerId+i) % 7);
                }
            }
            round++;
        }
        // cari pemenang
        kombo.clear();
        for(int i = 0; i < players.size(); i++){
            Kombo k(players[i].getCard(), table.getMainDeck());
            kombo.push_back(k.value(1.39*9+0.01));
        }
        bool found = false;
        int i = 0;
        int winner;
        while(!found){
            if(*max_element(kombo.begin(), kombo.end()) == kombo[i]){
                found = true;
                winner = i+1;
            }
        }

        // berikan poin total pada pemenang
        players[winner-1].addPoin(poinTotal);
        showPoin();

        // reset untuk game berikutnya
        for(int i = 0; i < players.size(); i++){
            players[i].resetNewGame();
        }
        poinTotal = 64;
        table.resetNewGame();
        round = 1;
        game++;
        
    }
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
    while(!end){
        if(players[i].getPoin() >= pow(2,32)){
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
        table.randomTableDeck();
    }
    else{
        cout << "Masukkan nama file: " << endl;
        // exception ....
        string filename;
        table.readFileTumpukan(filename);
    }
}