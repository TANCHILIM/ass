#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

void displayMenu()
{
    cout << "+---------------------------------------------+" << endl;
    cout << "|              Alien vs zombie                |" << endl;
    cout << "|=============================================|" << endl;
    cout << "| Select:                                     |" << endl;
    cout << "| 1 => Start game                             |" << endl;
    cout << "| 2 => Load                                   |" << endl;
    cout << "|---------------------------------------------|" << endl;
    cout << "| Q => Quit                                   |" << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << endl;
    cout << "Choice => ";
}

void gameset(int &row, int &column, int &zombie)
{
    // system("cls");
    bool rowdone, columndone, zombiedone;
    cout << "+-----------------------------+" << endl;
    cout << "|        Game Settings        |" << endl;
    cout << "+-----------------------------+" << endl;
    cout << "Enter rows => ";
    cin >> row;
    while (cin.fail() || row % 2 == 0 || row < 4 || row > 49)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter an valid odd rows (5 - 49): ";
        cin >> row;
    }

    cout << "Enter columns => ";
    cin >> column;
    while (cin.fail() || column % 2 == 0 || column < 4 || column > 49)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter an valid odd columns (5 - 49): ";
        cin >> column;
    }

    cout << "Enter numbers of zombie => ";
    cin >> zombie;
    while (cin.fail() || zombie > 4)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter a zombie number which is not more than 4: ";
        cin >> zombie;
    }
}

void defaultset(int &row, int &column, int &zombie, bool mainload)
{
    // system("cls");
    char change;
    bool done = false;
    row = 5;
    column = 9;
    zombie = 1;
    if (mainload == false)
    {
        cout << "    Default Game setting    " << endl;
        cout << "+--------------------------+" << endl;
        cout << "Board Rows\t:" << row << endl;
        cout << "Board Columns\t:" << column << endl;
        cout << "Zombie Count\t:" << zombie << endl;
        cout << endl;

        cout << endl;
        do
        {
            cout << "Do you wish to change the game settings (y/n)? => ";
            cin >> change;
            change = toupper(change);
            switch (change)
            {
            case 'Y':
                gameset(row, column, zombie);
                done = true;
                break;
            case 'N':
                done = true;
                break;
            default:
                cout << "Invalid selection, try again!" << endl;
                cout << endl;
                break;
            }
        } while (!done);
    }
}

void board(int row, int column, int zombie, char *random, int alife, int aattack, int *zombdata)
{
    cout << ".: Alien vs Zombie :." << endl;
    int r;
    int c;
    int z = 0;
    int n;
    char ran;
    for (r = 0; r < row; r++)
    {
        cout << " ";
        if (row > 9)
        {
            cout << " ";
        }
        for (c = 0; c < column; c++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        if (row > 9 && r < 9)
        {
            cout << " ";
        }
        cout << r + 1;
        for (c = 0; c < column; c++)
        {
            cout << "|";
            // cout << random[r][c];
            char check = *(random + r * 50 + c);
            if (check == 'e')
            {
                cout << ' ';
            }
            else
            {
                cout << *(random + r * 50 + c);
            }
        }
        cout << "|" << endl;
    }
    cout << " ";
    if (row > 9)
    {
        cout << " ";
    }
    for (c = 0; c < column; c++)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    int tens = (column - 10) / 10;
    int dec = column % 10;
    int t = 1;
    int d;
    if (column > 10)
    {
        if (row > 10)
        {
            cout << " ";
        }
        cout << "  ";
        for (c = 0; c < 9; c++)
        {
            cout << "  ";
        }
        for (t = 0; t < tens; t++)
        {
            for (c = 0; c < 10; c++)
            {
                cout << t + 1 << " ";
            }
        }
        for (d = 0; d <= dec; d++)
        {
            cout << t + 1 << " ";
        }
        cout << endl;
        if (row > 10)
        {
            cout << " ";
        }
        cout << " ";
        int m = 1;
        for (m = 0; m <= tens; m++)
        {
            for (c = 1; c < 10; c++)
            {
                cout << " " << c;
            }
            cout << " 0";
        }
        for (d = 1; d <= dec; d++)
        {
            cout << " " << d;
        }
    }
    else
    {
        if (row > 10)
        {
            cout << " ";
        }
        cout << "  ";
        for (d = 1; d <= dec; d++)
        {
            cout << d << " ";
        }
    }
    cout << endl
         << endl
         << "-> Alien   : Life " << alife << ", Attack " << aattack << endl;
    for (z = 0; z < zombie; z++)
    {
        cout << "   Zombie " << z + 1 << ": Life " << *(zombdata + z * 6) << ", Attack " << *(zombdata + z * 6 + 1) << ", Range " << *(zombdata + z * 6 + 2) << endl;
    }
    cout << endl;
}

void help()
{
    cout << "           Object           " << endl;
    cout << "+--------------------------+" << endl;
    cout << "'a'\t:alien (you)" << endl;
    cout << "'z'\t:zombie (your enemy)" << endl;
    cout << "'h'\t:health (add 20 life to alien) " << endl;
    cout << "'p'\t:pod (instanly inflicts 10 damage to zombie when hit by alien) " << endl;
    cout << "'r'\t:rock (hides a game object, reveals when hit by alien, stop when hit by alien" << endl;
    cout << "' '\t:space (just a empty space)" << endl;
    cout << "'.'\t:trial (left by alien moves, reset to random object after Alien's turn ends) " << endl;
    cout << "           Command           " << endl;
    cout << "+---------------------------+" << endl;
    cout << "up\t:Alien to move up." << endl;
    cout << "down\t:Alien to move down." << endl;
    cout << "left\t:Alien to move left." << endl;
    cout << "right\t:Alien to move right." << endl;
    cout << "arrow\t:Switch the direction of an arrow object in the game board." << endl;
    cout << "help\t:List and describe the commands that the player can use in the game." << endl;
    cout << "save\t:Save the current game to a file." << endl;
    cout << "load\t:Load a saved game from a file." << endl;
    cout << "quit\t:Quit the game while still in play." << endl;
    cout << endl;
    cout << "Press any key to continue . . .";
    string cintocontinue;
    cin >> cintocontinue;
    ;
    // system("cls");
    cout << endl;
}

void al(int &alife, int &aattack)
{
    alife = 100;
    aattack = 0;
}

void game(int row, int column, int zombie, bool &mainload)
{
    // system("cls");
    bool win = false;
    bool zombiedead = false;
    bool playerquit = false;
    char com, ran;
    int r, c, z;
    int w = (column * 2 - 19) / 2;
    int alife = 100;
    int aattack = 0;
    int zombiedeadnum = 0;
    int zlife, zattack, range;
    vector<char> object = {'^', 'v', '<', '>', 'h', 'p', 'r', 'e'};
    vector<char> norock = {'^', 'v', '<', '>', 'h', 'p', 'e'};
    char random[50][50];
    int zombdata[4][6];
    srand(time(NULL));
    int o = object.size();
    int nrock = norock.size();
    for (c = 0; c < w; c++)
    {
        cout << " ";
    }
    cout << " ";
    if (row > 9)
    {
        cout << " ";
    }
    if (mainload == false)
    {
        for (r = 0; r < row; r++)
        {
            for (c = 0; c < column; c++)
            {
                ran = object[rand() % o];
                random[r][c] = ran;
            }
        }

        random[row / 2][column / 2] = 'A';

        for (z = 0; z < zombie;)
        {
            r = rand() % (row - 1);
            c = rand() % (column - 1);
            if ((random[r][c] == 'A') || (random[r][c] == 'Z'))
            {
            }
            else
            {
                zombdata[z][4] = r;
                zombdata[z][5] = c;
                random[r][c] = 'Z';
                z += 1;
            }
        }

        for (int z = 0; z < zombie; z++)
        {
            char zombienumber = char(49 + z);
            int zr = zombdata[z][4];
            int zc = zombdata[z][5];
            random[zr][zc] = zombienumber;
        }
    }

    al(alife, aattack);
    // zombie data
    for (z = 0; z < zombie; z++)
    {
        zlife = ((rand() % 4) * 50 + 100);
        zombdata[z][0] = zlife;
        zattack = ((rand() % 3) * 5 + 5);
        zombdata[z][1] = zattack;
        range = ((rand() % 3) + 1);
        zombdata[z][2] = range;
    }

    do
    {
        bool turn = false;
        string command;
        char com;
        do
        {
            int arrowrow, arrowcolumn;
            char direction;
            bool arrowdone = false;
            while (!arrowdone)
            {
                if (mainload == false)
                {
                    board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                    cout << "command> ";
                    cin >> command;
                }
                else
                {
                    string name;
                    cout << "Enter the name of your file: ";
                    cin >> name;
                    string file = ".txt";
                    string fileName = name + file;
                    ifstream MyFile;
                    char check;
                    MyFile.open(fileName);
                    if (MyFile.fail())
                    {
                        cout << "File does not exist" << endl;
                    }
                    else
                    {
                        MyFile >> row;
                        MyFile >> column;
                        MyFile >> zombie;
                        for (int i = 0; i < row; i++)
                        {
                            for (int j = 0; j < column; j++)
                            {
                                MyFile >> random[i][j];
                                // cout << random[i][j] << "|";
                            }
                            // cout << endl;
                        }
                        for (int z = 0; z < zombie; z++)
                        {
                            for (int j = 0; j < 6; j++)
                            {
                                MyFile >> zombdata[z][j];
                            }
                        }
                        MyFile.close();
                        cout << "Press any key to continue . . .";
                        string cintocontinue;
                        cin >> cintocontinue;
                        mainload = false;
                        board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                        cout << "command> ";
                        cin >> command;
                    }
                }

                if (command == "arrow")
                {
                    cout << "Enter row, column, and direction: ";
                    cin >> arrowrow >> arrowcolumn >> direction;
                    // cout << arrowrow << arrowcolumn << direction;
                    if (random[arrowrow - 1][arrowcolumn - 1] == '^' || random[arrowrow - 1][arrowcolumn - 1] == 'v' || random[arrowrow - 1][arrowcolumn - 1] == '<' || random[arrowrow - 1][arrowcolumn - 1] == '>')
                    {
                        switch (direction)
                        {
                        case 'u':
                            random[arrowrow - 1][arrowcolumn - 1] = '^';
                            break;
                        case 'd':
                            random[arrowrow - 1][arrowcolumn - 1] = 'v';
                            break;
                        case 'l':
                            random[arrowrow - 1][arrowcolumn - 1] = '<';
                            break;
                        case 'r':;
                            random[arrowrow - 1][arrowcolumn - 1] = '>';
                            break;
                        }
                        cout << "The direction of arrow was changed." << endl;
                        cout << "Press any key to continue . . .";
                        string cintocontinue;
                        cin >> cintocontinue;
                        // system("cls");
                    }
                    else
                    {
                        cout << "That is not an arrow.";
                        cout << "Press any key to continue . . .";
                        string cintocontinue;
                        cin >> cintocontinue;
                        // system("cls");
                    }
                }
                else if (command == "up")
                {
                    com = '^';
                    arrowdone = true;
                }
                else if (command == "down")
                {
                    com = 'v';
                    arrowdone = true;
                }
                else if (command == "left")
                {
                    com = '<';
                    arrowdone = true;
                }
                else if (command == "right")
                {
                    com = '>';
                    arrowdone = true;
                }
                else if (command == "save")
                {
                    const int m = column, n = row;
                    string name;
                    cout << "Choose a name to save current file: ";
                    cin >> name;
                    string file = ".txt";
                    string fileName = name + file;
                    ofstream MyFile(fileName);
                    MyFile << row << endl
                           << column << endl
                           << zombie << endl;
                    for (int i = 0; i < row; i++)
                    {
                        for (int j = 0; j < column; j++)
                        {
                            MyFile << random[i][j] << endl;
                        }
                    }
                    for (int z = 0; z < zombie; z++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            MyFile << zombdata[z][j] << endl;
                        }
                    }
                    MyFile << alife << endl;
                    MyFile << aattack << endl;
                    cout << "File saved successfully" << endl;
                    cout << "Press any key to continue . . .";
                    string cintocontinue;
                    cin >> cintocontinue;
                    // system("cls");
                    cout << endl;
                    MyFile.close();
                }
                else if (command == "load")
                {
                    const int m = column, n = row;
                    string name;
                    cout << "Enter the name of your file: ";
                    cin >> name;
                    string file = ".txt";
                    string fileName = name + file;
                    ifstream MyFile;
                    char check;
                    MyFile.open(fileName);
                    if (MyFile.fail())
                    {
                        cout << "File does not exist" << endl;
                    }
                    else
                    {
                        MyFile >> row;
                        MyFile >> column;
                        MyFile >> zombie;
                        for (int i = 0; i < row; i++)
                        {
                            for (int j = 0; j < column; j++)
                            {
                                MyFile >> random[i][j];
                                // cout << random[i][j] << "|";
                            }
                            // cout << endl;
                        }
                        for (int z = 0; z < zombie; z++)
                        {
                            for (int j = 0; j < 6; j++)
                            {
                                MyFile >> zombdata[z][j];
                            }
                        }
                        MyFile.close();
                        cout << "Press any key to continue . . .";
                        string cintocontinue;
                        cin >> cintocontinue;
                        // system("cls");
                    }
                }
                else if (command == "quit")
                {
                    playerquit = true;
                    // system("cls");
                    break;
                }
                else
                {
                    help();
                }
            }

            if (playerquit == false)
            {
                bool movedone = false;
                int ar, ac, zr, zc;
                char going;
                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < column; c++)
                    {
                        char A = random[r][c];
                        if (A == 'A')
                        {
                            ar = r;
                            ac = c;
                        }
                    }
                }
                int gr, gc;
                while (!movedone)
                {
                    switch (com)
                    {
                    // get going palce
                    case '^':
                        gr = ar - 1;
                        gc = ac;
                        going = random[gr][gc];
                        break;
                    case 'v':
                        gr = ar + 1;
                        gc = ac;
                        going = random[gr][gc];
                        break;
                    case '<':
                        gr = ar;
                        gc = ac - 1;
                        going = random[gr][gc];
                        break;
                    case '>':
                        gr = ar;
                        gc = ac + 1;
                        going = random[gr][gc];
                        break;
                    }
                    // done

                    // check going place
                    char nextcom;
                    string alienstatus, zombielifedamage, zombiestatus;

                    switch (going)
                    {
                    case '^':
                        alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                        aattack = aattack + 20;
                        nextcom = '^';
                        break;
                    case 'v':
                        alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                        aattack = aattack + 20;
                        nextcom = 'v';
                        break;
                    case '<':
                        alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                        aattack = aattack + 20;
                        nextcom = '<';
                        break;
                    case '>':
                        alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                        aattack = aattack + 20;
                        nextcom = '>';
                        break;
                    case 'h':
                        nextcom = com;
                        alife = alife + 20;
                        if (alife > 100)
                        {
                            alife = 100;
                            alienstatus = "Alien finds a health bag, alien's health is increaces by 20.\nAlien's health in limited at 100.\n";
                        }
                        else
                        {
                            alienstatus = "Alien finds a health bag, alien's health is increaces by 20.\n";
                        }
                        break;
                    case 'p':
                    {
                        int check;
                        nextcom = com;
                        bool podatt = false;
                        int ragr = -1;
                        int ragc = -1;
                        int ragrt, ragct;
                        int zombieinrange = 0;
                        cout << "Alien finds a pod.\n";
                        while (podatt == false)
                        {
                            for (ragrt = ragr; ragrt <= -ragr; ragrt++)
                            {
                                int arragrt = gr + ragrt;
                                if (arragrt < 0)
                                {
                                    arragrt = 0;
                                    ragrt = 0;
                                }
                                for (ragct = ragc; ragct <= -ragc; ragct++)
                                {
                                    for (z = 0; z < zombie; z++)
                                    {
                                        char go = (z + 49);
                                        int acragct = gc + ragct;
                                        char alienattacting = random[arragrt][acragct];
                                        if (acragct < 0)
                                        {
                                            acragct = 0;
                                            ragct = 0;
                                            alienattacting = random[arragrt][acragct];
                                        }
                                        else if (acragct > column)
                                        {
                                            alienattacting = 'e';
                                        }

                                        if (alienattacting == go)
                                        {
                                            zombieinrange = zombieinrange + 1;
                                            zombdata[z][3] = 1;
                                        }
                                    }
                                }
                            }
                            if (zombieinrange > 0)
                            {
                                while (podatt == false)
                                {
                                    int rannum = rand() % 5;
                                    char zombpod = (rannum + 49);
                                    if (zombdata[rannum][3] == 1)
                                    {
                                        zombdata[rannum][0] = zombdata[rannum][0] - 10;
                                        cout << "Zombie " << zombpod << " receive 10 damage" << endl;
                                        if (zombdata[rannum][0] <= 0) // not yet receive damage
                                        {
                                            cout << "Zombie " << zombpod << " is dead\n";
                                            random[gr][gc] = 'e';
                                            zombiedeadnum = zombiedeadnum + 1;
                                        }
                                        else
                                        {
                                            cout << "Zombie " << zombpod << " is still alive\n";
                                        }
                                        podatt = true;
                                    }
                                }
                            }
                            else
                            {
                                ragc = ragc - 1;
                                ragr = ragr - 1;
                            }
                        }
                        break;
                    }
                    case 'r':
                        com = 's';
                        nextcom = 's';
                        ran = norock[rand() % nrock];
                        random[gr][gc] = ran;
                        alienstatus = "Alien hits a rock, the object beneath the rock is revealed.\n";
                        break;
                    case 'e':
                        nextcom = com;
                        alienstatus = "Alien finds an empty space.\n";
                        break;
                    case '.':
                        nextcom = com;
                        alienstatus = "Alien finds an empty space.\n";
                        break;
                    default:
                        com = 's';
                        alienstatus = "Alien reached the side of the game.\n";
                        break;
                    }

                    if (ar == 0 && com == '^')
                    {
                        break;
                    }
                    else if (ar == row - 1 && com == 'V')
                    {
                        break;
                    }
                    else if (ac == 0 && com == '<')
                    {
                        break;
                    }
                    else if (ac == column - 1 && com == '>')
                    {
                        break;
                    }
                    //
                    for (z = 0; z < zombie; z++)
                    {
                        char go = (z + 49);
                        if (going == go)
                        {
                            zombdata[z][0] = zombdata[z][0] - aattack;
                            cout << "Alien attacks Zombie " << go << "\nZombie " << go << " receives a damage of " << aattack << endl;
                            alienstatus = "Alien hits zombie and stop.\n";
                            if (zombdata[z][0] <= 0)
                            {
                                cout << "Zombie " << go << " is dead\n";
                                random[gr][gc] = 'e';
                                zombiedeadnum = zombiedeadnum + 1;
                            }
                            else
                            {
                                cout << "Zombie " << go << " is still alive\n";
                            }
                        }
                    }

                    cout << alienstatus;
                    cout << "Press any key to continue . . .";
                    string cintocontinue;
                    cin >> cintocontinue;
                    // system("cls");
                    switch (com)
                    {
                    case '^':
                        random[ar][ac] = '.';
                        random[ar - 1][ac] = 'A';
                        ar = ar - 1;
                        break;
                    case 'v':
                        random[ar][ac] = '.';
                        random[ar + 1][ac] = 'A';
                        ar = ar + 1;
                        break;
                    case '<':
                        random[ar][ac] = '.';
                        random[ar][ac - 1] = 'A';
                        ac = ac - 1;
                        break;
                    case '>':
                        random[ar][ac] = '.';
                        random[ar][ac + 1] = 'A';
                        ac = ac + 1;
                        break;
                    case 's':
                        alienstatus = "";
                        turn = true;
                        movedone = true;
                        break;
                    }
                    board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                    com = nextcom;
                }
            }

            if (zombiedeadnum == zombie)
            {
                zombiedead = true;
            }
            if (zombiedead == false && playerquit == false)
            {
                cout << "Alien's turn ended.\n";
                cout << "Press any key to continue . . .";
                string cintocontinue;
                cin >> cintocontinue;
                // system("cls");
                aattack = 0;
                string alienturn;
                int alientrial = 0;
                for (r = 0; r < row; r++)
                {
                    for (c = 0; c < column; c++)
                    {
                        if (random[r][c] == '.')
                        {
                            ran = object[rand() % o];
                            random[r][c] = ran;
                            alienturn = "Alien's trial '.' is replaced by random objects.\n";
                            alientrial = alientrial + 1;
                        }
                    }
                }
                if (alientrial > 0)
                {
                    board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                    cout << alienturn;
                    cout << "Press any key to continue . . .";
                    string cintocontinue;
                    cin >> cintocontinue;
                    // system("cls");
                }

                bool zombieturndone = false;
                while (!zombieturndone)
                {
                    // add zombie move
                    int zr, zc;
                    char zombienextplace;
                    string zombiegoing;
                    bool alieninrange = true;
                    for (z = 0; z < zombie; z++)
                    {
                        board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                        cout << "Zombie " << z + 1 << "'s turn." << endl;
                        cout << "Press any key to continue ...";
                        char cintocontinue;
                        cin >> cintocontinue;
                        // system("pause")
                        int range = zombdata[z][2];
                        char zombienumber = (z + 49);
                        bool zombiemovedone = false;
                        bool zombiecanmove = true;
                        while (!zombiemovedone)
                        {
                            zr = zombdata[z][4];
                            zc = zombdata[z][5];
                            int zombiemove = rand() % 4;
                            if (zombiemove == 0 && zombdata[z][4] > 0)
                            {
                                for (int zt = 0; zt < zombie; zt++)
                                {
                                    zombienextplace = random[zombdata[z][4] - 1][zombdata[z][5]];
                                    char go = (zt + 49);
                                    if (zombienextplace == go || zombienextplace == 'A')
                                    {
                                        zombiecanmove = false;
                                    }
                                }
                                if (zombiecanmove == true)
                                {
                                    zombdata[z][4] -= 1;
                                    zombiegoing = "up";
                                    random[zr][zc] = ' ';
                                    random[zr - 1][zc] = zombienumber;
                                    zombiemovedone = true;
                                }
                            }
                            else if (zombiemove == 1 && zombdata[z][4] < row)
                            {
                                for (int zt = 0; zt < zombie; zt++)
                                {
                                    zombienextplace = random[zombdata[z][4] + 1][zombdata[z][5]];
                                    char go = (zt + 49);
                                    if (zombienextplace == go || zombienextplace == 'A')
                                    {
                                        zombiecanmove = false;
                                    }
                                }
                                if (zombiecanmove == true)
                                {
                                    zombdata[z][4] += 1;
                                    zombiegoing = "down";
                                    random[zr][zc] = ' ';
                                    random[zr + 1][zc] = zombienumber;
                                    zombiemovedone = true;
                                }
                            }
                            else if (zombiemove == 2 && zombdata[z][5] > 0)
                            {
                                for (int zt = 0; zt < zombie; zt++)
                                {
                                    zombienextplace = random[zombdata[z][4]][zombdata[z][5] - 1];
                                    char go = (zt + 49);
                                    if (zombienextplace == go || zombienextplace == 'A')
                                    {
                                        zombiecanmove = false;
                                    }
                                }
                                if (zombiecanmove == true)
                                {
                                    zombdata[z][5] -= 1;
                                    zombiegoing = "left";
                                    random[zr][zc] = ' ';
                                    random[zr][zc - 1] = zombienumber;
                                    zombiemovedone = true;
                                }
                            }
                            else if (zombiemove == 3 && zombdata[z][4] < column)
                            {
                                for (int zt = 0; zt < zombie; zt++)
                                {
                                    zombienextplace = random[zombdata[z][4]][zombdata[z][5] + 1];
                                    char go = (zt + 49);
                                    if (zombienextplace == go || zombienextplace == 'A')
                                    {
                                        zombiecanmove = false;
                                    }
                                }
                                if (zombiecanmove == true)
                                {
                                    zombdata[z][5] += 1;
                                    zombiegoing = "right";
                                    random[zr][zc] = ' ';
                                    random[zr][zc + 1] = zombienumber;
                                    zombiemovedone = true;
                                }
                            }
                        }
                        board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                        cout << "Zombie " << zombienumber << " move " << zombiegoing << endl;
                        cout << "Press any key to continue ...";
                        cin >> cintocontinue;
                        // system("pause")
                        zr = zombdata[z][4];
                        zc = zombdata[z][5];
                        for (int ragr = -range; ragr <= range; ragr++)
                        {
                            for (int ragc = -range; ragc <= range; ragc++)
                            {
                                char zombieattacking = random[zr + ragr][zc + ragc];
                                if (zombieattacking == 'A')
                                {
                                    int zombatt = zombdata[z][1];
                                    alife = alife - zombatt;
                                    board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                                    cout << "Alien is in the range of Zombie " << z + 1 << endl;
                                    cout << "Alien life reduce by " << zombdata[z][1] << endl;

                                    ragc = range + 1;
                                    ragr = range + 1;
                                    alieninrange = true;
                                    if (alife <= 0)
                                    {
                                        cout << "Alien die.\nYou lose the game!" << endl;
                                        turn = true;
                                        win = true;
                                        zombieturndone = true;
                                        z = zombie;
                                    }
                                    else
                                    {
                                        cout << "Alien is still alive.\n";
                                    }
                                    cout << "Press any key to continue ...";
                                    char cintocontinue;
                                    cin >> cintocontinue;
                                    // system("pause")
                                }
                                else
                                {
                                    alieninrange = false;
                                }
                            }
                        }
                        if (alieninrange == false)
                        {
                            board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                            cout << "Alien is not in range of Zombie " << z + 1 << endl;
                            cout << "Press any key to continue ...";
                            char cintocontinue;
                            cin >> cintocontinue;
                            // system("pause")
                        }
                    }
                    zombieturndone = true;
                }
            }
            else if (zombiedead == true)
            {
                turn = true;
                win = true;
                cout << "All zombie is dead.\nYou win!" << endl;
                cout << "Press any key to continue . . .";
                string cintocontinue;
                cin >> cintocontinue;
                // system("cls");
            }
            else if (playerquit == true)
            {
                turn = true;
                win = true;
            }
        } while (!turn);
    } while (!win);
}

int main()
{
    // system("cls");
    int row, column, zombie;
    char choice;
    bool done = false;
    bool mainload = false;
    do
    {
        displayMenu();
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
        switch (choice)
        {
        case '1':
            defaultset(row, column, zombie, mainload);
            game(row, column, zombie, mainload);
            break;
        case '2':
            mainload = true;
            defaultset(row, column, zombie, mainload);
            game(row, column, zombie, mainload);
            break;
        case 'Q':
            done = true;
            break;
        default:
            cout << "Invalid selection, try again!" << endl;
            cout << endl;
            break;
        }
    } while (!done);
    cout << endl;
    cout << "Good Bye!" << endl;
}
