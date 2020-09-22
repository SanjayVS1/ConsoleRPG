#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;
class characters{
public:
    string name;
    int power;

    void battle(characters opponent, characters player);

};

void battle(characters opponent, characters player){
    char key_input;
    int player_choice, opponent_choice, battle_result;

    cout <<"\n"<<player.name<< " is currently battling "<<opponent.name;

    while(!(opponent.power<=0) || (player.power<=0)){
        cout<<"\n[0]attack or [1]defend\n";

        key_input = getch();
        player_choice = key_input;

        if (rand()%2==0){

            opponent_choice = 0;
        }else{
            opponent_choice = 1;
        }

        system("cls");

        if (opponent_choice == 0 && player_choice==49)
        {
            player.power = player.power - 15;
            cout<<"You defended "<<opponent.name<<"\'s attack\n";
        }
        else if(opponent_choice == 0 && player_choice==48)
        {
            player.power = player.power - 20;
            opponent.power = opponent.power - 20;
            cout<<"You and "<<opponent.name<<" also attacked\n";
        }
        else if(opponent_choice == 1 && player_choice==49){
            opponent.power = opponent.power;
            cout<<"You and "<<opponent.name<<" also defended\n";
        }else if(opponent_choice == 1 && player_choice==48){
            opponent.power = opponent.power - 15;
            cout<<"You attacked but "<<opponent.name<<" defended your attack\n";
        }

        cout<<"Your HP: "<<player.power<<"\n";
        cout<<opponent.name<<"\'s HP: "<<opponent.power<<"\n\n";

        if (opponent.power <= 0){
            battle_result = 1;
            break;
        }else if (player.power <= 0){
            battle_result = 0;
            break;
        }
    }
    if (battle_result==1){
        cout<<"you have won\n\n";
        cout<<"Enter any key to continue";
        key_input = getch();
     }else if (battle_result==0){
        cout<< "you have lost\n\n";
        cout<<"Enter any key to continue";
        key_input = getch();
     }
}

int main()
{
    string choice;

    char key_press;
    int a_value;
    int x=0;
    int y=0;
    int i;

    characters one;
    one.name = "One";
    one.power = 90;

    characters two;
    two.name = "Two";
    two.power = 110;

    characters mainc;
    mainc.power = 100;

    string map[]  = {"0...................",
                     "....................",
                     "....................",
                     "....................",
                     "....1.........2.....",
                     "....................",
                     "....................",
                     "....................",
                     "....................",
                     "...................."};


    cout << "Game started:\n";
    cout << "Enter name for your character: ";
    cin>>mainc.name;
    cout<<"\nWelcome "<<mainc.name<<"\n";
    system("cls");

    while(1){
        system("cls");
        cout<<"========={{Map}}========\n";
        for (i=0;i<10;i++)
        {
            if(x==i)
            {
                map[x].replace(y,1,"0");
            }
            cout<<"||"<<map[i]<<"||"<<"\n";
        }
        cout<<"========================\n";

        key_press = getch();
        a_value = key_press;

        if(a_value == 72){
            //up key
            if(x==0){
            }else{
                x--;
            }
        }else if(a_value == 80){
            //down key
            if(x==9){
            }else{
                x++;
            }
        }else if(a_value == 75){
            //left key
            if(y==0){
            }else{
                y--;
            }
        }else if(a_value == 77){
            //right key
            if(y==19){
            }else{
                y++;
            }
        }else if(a_value == 27){
            return 1;
        }

        map[0]= "....................";
        map[1]= "....................";
        map[2]= "....................";
        map[3]= "....................";
        map[4]= "....1.........2.....";
        map[5]= "....................";
        map[6]= "....................";
        map[7]= "....................";
        map[8]= "....................";
        map[9]= "....................";

        if(x==4&&y==4)
        {
            battle(one,mainc);
            y++;
        }else if(x==4&&y==14)
        {
            battle(two,mainc);
            y++;
        }

        for (i=0;i<10;i++)
        {
            if(x==i)
            {
                map[x].replace(y,1,"0");
            }
        }
    }
    return 0;
}
