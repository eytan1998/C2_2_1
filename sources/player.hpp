


class Player {
public:
    string name;
    explicit Player(string Pname) {
        name = Pname;
    }

//prints the amount of cards left. should be 21 but can be less if a draw was played
    int stacksize(){
        return 0;
    }
    // prints the amount of cards this player has won.
    int cardesTaken(){
        return 0;
    }
};