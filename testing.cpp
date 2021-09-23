void twoPlyr()
{   
    //Seed the random number generator
    srand(time(0));
    
    //Declare variables
    unsigned short card = 0;                    //Card drawn (Random)
    unsigned short choice, pChoice = 0;         //Which option the user wants after they draw a card
    unsigned short p1cPosn = 0;                 //Player 1's current position on the game board
    unsigned short p2cPosn = 0;                 //Player 2's current position on the game board
    unsigned short temp = 0;                    //Hold a temporary value
    bool restart = false;                       //Bypasses the remaining players turn
    string pOnePos[TPOSTNS];                    //Array containing Player 1 game boards (*)
    string pTwoPos[TPOSTNS];                    //Array containing Player 2 game boards (#)
    string p1Sstrg, p2Sstrg;                    //Player 1 & 2 substrings
    size_t pos1 = 0, pos2;                      //Cursors for creating substrings
    stringstream buffer;                        //variable for the string stream buffer
    
    //Output Title
    cout << endl;
    cout << setw(20) << "2 player Mode" << endl;
    cout << endl;
    
    //Print players and their symbols
    cout << "Player 1 \t Player 2" << endl;
    cout << "-------- \t --------" << endl;
    cout << "    *    \t     #   " << endl;
    
    //Load the text file for player 1
    ifstream in_p1("Player1_GameBoards.txt");
    buffer << in_p1.rdbuf();
    p1Sstrg = buffer.str();
    
    //Read the text file into the player 1 array
    for(int i = 0; i < TPOSTNS; i++)
    {
        pos2 = p1Sstrg.find(",", pos1);                    //Search for the "," (position 2 will be where the comma was found)
        pOnePos[i] = p1Sstrg.substr(pos1, (pos2-pos1));    //Make the substring
        pos1 = pos2 + 1;
    }
    
    //Load the text file for player 2
    ifstream in_p2("Player2_GameBoards.txt");
    buffer << in_p2.rdbuf();
    p2Sstrg = buffer.str();
    
    //Read the text file into the player 2 array
    for(int c = 0; c < TPOSTNS; c++)
    {
        pos2 = p2Sstrg.find(",", pos1);                     //Search for the "," (position 2 will be where the comma was found)
        pTwoPos[c] = p2Sstrg.substr(pos1, (pos2-pos1));     //Make the substring
        pos1 = pos2 + 1;
    }
    
    //Begin the game
    //Loop until a player exceeds their native 74th position
    while(p1cPosn < 74 && p2cPosn < 74)
    {
        cout << endl;
        cout << setw(25) << "PLAYER 1'S TURN:";
        cout << "\nPress the Enter key to draw a card! ";
        cin.get();

        //generate a random card
        card = (rand() % 11) + 1;
        cout << endl;

        //Determine the card value and apply the rules
        //Player 1 draws a "1"
        if(card == 1)
        {
            //Print the card's specific menu
            cout << "You drew a 1!" << endl;
            cout << "1. Start" << endl;
            cout << "2. Move 1 space forward" << endl;
            cout << "3. Skip turn" << endl;

            //Check for legal move
            do
            {
                if((pChoice > 3) || (pChoice == 1 && p1cPosn >= 9) || (pChoice == 2 && p1cPosn < 9) || (pChoice == 3))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);                
            }while((pChoice > 3) || (pChoice == 1 && p1cPosn >= 9) || (pChoice == 2 && p1cPosn < 9) || (pChoice == 3));

            //Execute the desired action
            switch(pChoice)
            {
                case 1: 
                    p1cPosn = 10;
                    cout << pOnePos[p1cPosn] << endl;   //Output modified game board
                    break;
                case 2:
                    p1cPosn += 1;
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 3:
                    break;
            }
        }

        //Player 1 draws a "2"
        else if(card == 2)
        {
            //Print the card's specific menu
            cout << "You drew a 2!" << endl;
            cout << "1. Start" << endl;
            cout << "2. Move 2 spaces forward" << endl;
            cout << "3. Skip turn" << endl;

            //Check for legal move
            do
            {
                if((pChoice > 3) || (pChoice == 1 && p1cPosn >= 9) || (pChoice == 1 && p1cPosn >= 9) || (pChoice == 3))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice); 
            }while((pChoice > 3) || (pChoice == 1 && p1cPosn >= 9) || (pChoice == 1 && p1cPosn >= 9) || (pChoice == 3));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn = 10;
                    cout << pOnePos[p1cPosn] << endl;   //Output modified game board
                    break;
                case 2:
                    p1cPosn += 2;
                    if(p1cPosn > 74)
                    {
                        p1cPosn = 74;
                    }
                    cout << pOnePos[p1cPosn] << endl;   //Output modified game board
                    break;
                case 3:
                    break;
            }
        }

        //Player 1 draws a "3"
        else if(card == 3)
        {
            //Print the card's specific menu
            cout << "You drew a 3!" << endl;
            cout << "1. Move 3 spaces forward" << endl;
            cout << "2. Skip turn" << endl;

            //Check for legal move 
            do
            {
                if((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);                    
            } while((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn += 3;
                    if(p1cPosn > 74)
                    {
                        p1cPosn = 74;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 2:
                    break;
            }
        }

        //Player 1 draws a "4"
        else if(card == 4)
        {
            //Print the card's specific menu
            cout << "You drew a 4!" << endl;
            cout << "1. Move 4 spaces backward" << endl;
            cout << "2. Skip turn" << endl;

            //Check for legal move
            do
            {
                if((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);
            } while((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn -= 4;                       

                    //Determine if Player 1 has moved before their safe zone (P1-0 - P1-8)
                    if(p1cPosn == 8)
                    {
                        p1cPosn = 68;
                    }
                    else if(p1cPosn == 7)
                    {
                        p1cPosn = 67;
                    }
                    else if(p1cPosn == 6)
                    {
                        p1cPosn = 66;
                    }
                    else if(p1cPosn == 5)
                    {
                        p1cPosn = 65;
                    }
                    else if(p1cPosn == 4)
                    {
                        p1cPosn = 64;
                    }
                    else if(p1cPosn == 3)
                    {
                        p1cPosn = 63;
                    }
                    else if(p1cPosn == 2)
                    {
                        p1cPosn = 62;
                    }
                    else if(p1cPosn == 1)
                    {
                        p1cPosn = 61;
                    }
                    else if(p1cPosn == 0)
                    {
                        p1cPosn = 60;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 2:
                    break;
            }
        }

        //Player 1 draws a "5"
        else if(card == 5)
        {
            //Print the card's specific menu
            cout << "You drew a 5!" << endl;
            cout << "1. Move 5 spaces forward" << endl;
            cout << "2. Skip turn" << endl;

            //Check for legal move
            do
            {
                if((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);  
            } while((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn += 5;
                    if(p1cPosn > 74)
                    {
                        p1cPosn = 74;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 2:
                    break;
            }
        }

        //Player 1 draws a "7"
        else if(card == 6)
        {
            //Print the card's specific menu
            cout << "You drew a 7!" << endl;
            cout << "1. Move 7 spaces forward" << endl;
            cout << "2. Move the opponent 7 spaces backward" << endl;
            cout << "3. Skip turn" << endl;

            //Check for legal move
            do
            {
                if((pChoice > 3) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p2cPosn < 9) || (pChoice == 3 && p1cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);
            } while((pChoice > 3) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p2cPosn < 9) || (pChoice == 3 && p1cPosn >= 9));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn += 7;
                    if(p1cPosn > 74)
                    {
                        p1cPosn = 74;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 2:
                    p2cPosn -= 7;                       

                    //Determine if Player 2 has moved before their safe zone (P1-0 - P1-8)
                    if(p2cPosn == 8)
                    {
                        p2cPosn = 68;
                    }
                    else if(p2cPosn == 7)
                    {
                        p2cPosn = 67;
                    }
                    else if(p2cPosn == 6)
                    {
                        p2cPosn = 66;
                    }
                    else if(p2cPosn == 5)
                    {
                        p2cPosn = 65;
                    }
                    else if(p2cPosn == 4)
                    {
                        p2cPosn = 64;
                    }
                    else if(p2cPosn == 3)
                    {
                        p2cPosn = 63;
                    }
                    else if(p2cPosn == 2)
                    {
                        p2cPosn = 62;
                    }
                    else if(p2cPosn == 1)
                    {
                        p2cPosn = 61;
                    }
                    else if(p2cPosn == 0)
                    {
                        p2cPosn = 60;
                    }
                    cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                    break;
                case 3:
                    break;
            }
        }

        //Player 1 draws an "8"
        else if(card == 7)
        {
            //Print the card's specific menu
            cout << "You drew an 8!" << endl;
            cout << "1. Move 8 spaces forward" << endl;
            cout << "2. Skip turn" << endl;

            //Check for legal move
            do
            {
                if((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);                
            } while((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn += 8;
                    if(p1cPosn > 74)
                    {
                        p1cPosn = 74;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 2:
                    break;
            }
        }

        //Player 1 draws a "10"
        else if(card == 8)
        {
            //Print the card's specific menu
            cout << "You drew a 10!" << endl;
            cout << "1. Move 10 spaces forward" << endl;
            cout << "2. Move 1 space backward" << endl;
            cout << "3. Skip turn" << endl;

            //Check for legal move
            do
            {
                if((pChoice > 3) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn < 9) || (pChoice == 3 && p1cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);                   
            }while((pChoice > 3) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn < 9) || (pChoice == 3 && p1cPosn >= 9));           

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn += 10;
                    if(p1cPosn > 74)
                    {
                        p1cPosn = 74;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 2:
                    p1cPosn -= 1;                        

                    //Determine if Player 1 has moved before their safe zone (P1-0 - P1-8)
                    if(p1cPosn == 8)
                    {
                        p1cPosn = 68;
                    }
                    else if(p1cPosn == 7)
                    {
                        p1cPosn = 67;
                    }
                    else if(p1cPosn == 6)
                    {
                        p1cPosn = 66;
                    }
                    else if(p1cPosn == 5)
                    {
                        p1cPosn = 65;
                    }
                    else if(p1cPosn == 4)
                    {
                        p1cPosn = 64;
                    }
                    else if(p1cPosn == 3)
                    {
                        p1cPosn = 63;
                    }
                    else if(p1cPosn == 2)
                    {
                        p1cPosn = 62;
                    }
                    else if(p1cPosn == 1)
                    {
                        p1cPosn = 61;
                    }
                    else if(p1cPosn == 0)
                    {
                        p1cPosn = 60;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 3:
                    break;
            }
        }

        //Player 1 draws an "11"
        else if(card == 9)
        {
            //Print the card's specific menu
            cout << "You drew an 11!" << endl;
            cout << "1. Move 11 spaces forward" << endl;
            cout << "2. Switch places with an opposing pawn" << endl;
            cout << "3. Skip turn" << endl;

            //Check for legal move 
            do
            {
                if((pChoice > 3) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn < 9) ||
                  (pChoice == 2 && p2cPosn < 9) || (pChoice == 3 && p1cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);
            } while((pChoice > 3) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn < 9) ||
                   (pChoice == 2 && p2cPosn < 9) || (pChoice == 3 && p1cPosn >= 9));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn += 11;
                    if(p1cPosn > 74)
                    {
                        p1cPosn = 74;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 2:
                    if(p1cPosn >= 15 && p2cPosn >= 15)
                    {
                        temp = p1cPosn;
                        p1cPosn = p2cPosn - 15;
                        p2cPosn = temp + 15;
                    }
                    else if(p1cPosn >= 15 && p2cPosn <= 15)
                    {
                        temp = p1cPosn;
                        p1cPosn = 60 + p2cPosn - 15;
                        p2cPosn = 15 - (60 - temp);
                    }
                    else if(p1cPosn <= 15 && p2cPosn <= 15)
                    {
                        temp = p1cPosn;
                        p1cPosn = 60 + p2cPosn - 15;
                        p2cPosn = temp + 15;
                    }
                    else if(p1cPosn <= 15 && p2cPosn >= 15)
                    {
                        p1cPosn = p2cPosn - 15;
                        p2cPosn = p2cPosn - (p1cPosn - 10);
                    }                       

                    //Determine if Player 1 has moved before their safe zone (P1-0 - P1-8)
                    if(p1cPosn == 8)
                    {
                        p1cPosn = 68;
                    }
                    else if(p1cPosn == 7)
                    {
                        p1cPosn = 67;
                    }
                    else if(p1cPosn == 6)
                    {
                        p1cPosn = 66;
                    }
                    else if(p1cPosn == 5)
                    {
                        p1cPosn = 65;
                    }
                    else if(p1cPosn == 4)
                    {
                        p1cPosn = 64;
                    }
                    else if(p1cPosn == 3)
                    {
                        p1cPosn = 63;
                    }
                    else if(p1cPosn == 2)
                    {
                        p1cPosn = 62;
                    }
                    else if(p1cPosn == 1)
                    {
                        p1cPosn = 61;
                    }
                    else if(p1cPosn == 0)
                    {
                        p1cPosn = 60;
                    }

                    //Determine if Player 2 has moved before their safe zone (P2-0 - P2-8)
                    if(p2cPosn == 8)
                    {
                        p2cPosn = 68;
                    }
                    else if(p2cPosn == 7)
                    {
                        p2cPosn = 67;
                    }
                    else if(p2cPosn == 6)
                    {
                        p2cPosn = 66;
                    }
                    else if(p2cPosn == 5)
                    {
                        p2cPosn = 65;
                    }
                    else if(p2cPosn == 4)
                    {
                        p2cPosn = 64;
                    }
                    else if(p2cPosn == 3)
                    {
                        p2cPosn = 63;
                    }
                    else if(p2cPosn == 2)
                    {
                        p2cPosn = 62;
                    }
                    else if(p2cPosn == 1)
                    {
                        p2cPosn = 61;
                    }
                    else if(p2cPosn == 0)
                    {
                        p2cPosn = 60;
                    }
                    cout << pOnePos[p1cPosn] << endl;
                    cout << endl;
                    cout << pTwoPos[p2cPosn] << endl;
                    break;
                case 3:
                    break;
            }
        }

        //Player 1 draws a "12"
        else if(card == 10)
        {
            //Print the card's specific menu
            cout << "You drew a 12!" << endl;
            cout << "1. Move 12 spaces forward" << endl;
            cout << "2. Skip turn" << endl;

            //Check for legal move 
            do
            {
                if((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);
            } while((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p1cPosn += 12;
                    if(p1cPosn > 74)
                    {
                        p1cPosn = 74;
                    }
                    cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                    break;
                case 2:
                    break;
            }
        }      

        //Player 1 draws a "Sorry!" card
        else
        {
            //Print the card's specific menu
            cout << "You drew a \"Sorry!\" Card!" << endl;
            cout << "1. Move an opponent's pawn off the game board!" << endl;
            cout << "2. Skip turn" << endl;

            //Check for legal move 
            do
            {
                if((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9))
                {
                    cout << "That's an illegal move!";
                }
                cout << "\nWhich choice would you like to make? ";
                pChoice = int_chk(choice);
            } while((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9));

            //Execute the desired action
            switch(pChoice)
            {
                case 1:
                    p2cPosn = 0;
                    cout << "\nPlayer 2 has been moved off the game board!" << endl;
                    cout << pTwoPos[0] << endl;
                    break;
                case 2:
                    break;
            }
        }

        //Determine whether Player 1 has won the game
        if(p1cPosn == 74)
        {
            cout << "\nPlayer 1 has won the game!" << endl;
            restart = true;
        }

        //Reset the player's choice
        pChoice = 0;
        
        //Begin Player 2's turn
        if(restart == false)
        {
            cout << endl;
            cout << setw(25) << "PLAYER 2'S TURN:";
            cout << "\nPress the Enter key to draw a card! ";  
            cin.ignore();
            cin.get();

            //generate a random card
            card = (rand() % 11) + 1;
            cout << endl;

            //Determine the card value and apply the rules
            //Player 2 draws a "1"
            if(card == 1)
            {
                //Print the card's specific menu
                cout << "You drew a 1!" << endl;
                cout << "1. Start" << endl;
                cout << "2. Move 1 space forward" << endl;
                cout << "3. Skip turn" << endl;

                //Check for legal move
                do
                {
                    if((pChoice > 3) || (pChoice == 1 && p2cPosn >= 9) || (pChoice == 2 && p2cPosn < 9) || (pChoice == 3))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);                
                }while((pChoice > 3) || (pChoice == 1 && p2cPosn >= 9) || (pChoice == 2 && p2cPosn < 9) || (pChoice == 3));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1: 
                        p2cPosn = 10;
                        cout << pTwoPos[p2cPosn] << endl;   //Output modified game board
                        break;
                    case 2:
                        p2cPosn += 1;
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 3:
                        break;
                }
            }

            //Player 2 draws a "2"
            else if(card == 2)
            {
                //Print the card's specific menu
                cout << "You drew a 2!" << endl;
                cout << "1. Start" << endl;
                cout << "2. Move 2 spaces forward" << endl;
                cout << "3. Skip turn" << endl;

                //Check for legal move
                do
                {
                    if((pChoice > 3) || (pChoice == 1 && p2cPosn >= 9) || (pChoice == 1 && p2cPosn >= 9) || (pChoice == 3))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice); 
                }while((pChoice > 3) || (pChoice == 1 && p2cPosn >= 9) || (pChoice == 1 && p2cPosn >= 9) || (pChoice == 3));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn = 10;
                        cout << pTwoPos[p2cPosn] << endl;   //Output modified game board
                        break;
                    case 2:
                        p2cPosn += 2;
                        if(p2cPosn > 74)
                        {
                            p2cPosn = 74;
                        }
                        cout << pTwoPos[p2cPosn] << endl;   //Output modified game board
                        break;
                    case 3:
                        break;
                }
            }

            //Player 2 draws a "3"
            else if(card == 3)
            {
                //Print the card's specific menu
                cout << "You drew a 3!" << endl;
                cout << "1. Move 3 spaces forward" << endl;
                cout << "2. Skip turn" << endl;

                //Check for legal move 
                do
                {
                    if((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);                    
                } while((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn += 3;
                        if(p2cPosn > 74)
                        {
                            p2cPosn = 74;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 2:
                        break;
                }
            }

            //Player 2 draws a "4"
            else if(card == 4)
            {
                //Print the card's specific menu
                cout << "You drew a 4!" << endl;
                cout << "1. Move 4 spaces backward" << endl;
                cout << "2. Skip turn" << endl;

                //Check for legal move
                do
                {
                    if((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);
                } while((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn -= 4;                       

                        //Determine if Player 2 has moved before their safe zone (P1-0 - P1-8)
                        if(p2cPosn == 8)
                        {
                            p2cPosn = 68;
                        }
                        else if(p2cPosn == 7)
                        {
                            p2cPosn = 67;
                        }
                        else if(p2cPosn == 6)
                        {
                            p2cPosn = 66;
                        }
                        else if(p2cPosn == 5)
                        {
                            p2cPosn = 65;
                        }
                        else if(p2cPosn == 4)
                        {
                            p2cPosn = 64;
                        }
                        else if(p2cPosn == 3)
                        {
                            p2cPosn = 63;
                        }
                        else if(p2cPosn == 2)
                        {
                            p2cPosn = 62;
                        }
                        else if(p2cPosn == 1)
                        {
                            p2cPosn = 61;
                        }
                        else if(p2cPosn == 0)
                        {
                            p2cPosn = 60;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 2:
                        break;
                }
            }

            //Player 2 draws a "5"
            else if(card == 5)
            {
                //Print the card's specific menu
                cout << "You drew a 5!" << endl;
                cout << "1. Move 5 spaces forward" << endl;
                cout << "2. Skip turn" << endl;

                //Check for legal move
                do
                {
                    if((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);  
                } while((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn += 5;
                        if(p2cPosn > 74)
                        {
                            p2cPosn = 74;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 2:
                        break;
                }
            }

            //Player 2 draws a "7"
            else if(card == 6)
            {
                //Print the card's specific menu
                cout << "You drew a 7!" << endl;
                cout << "1. Move 7 spaces forward" << endl;
                cout << "2. Move the opponent 7 spaces backward" << endl;
                cout << "3. Skip turn" << endl;

                //Check for legal move
                do
                {
                    if((pChoice > 3) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p1cPosn < 9) || (pChoice == 3 && p2cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);
                } while((pChoice > 3) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p1cPosn < 9) || (pChoice == 3 && p2cPosn >= 9));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn += 7;
                        if(p2cPosn > 74)
                        {
                            p2cPosn = 74;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 2:
                        p1cPosn -= 7;                       

                        //Determine if Player 1 has moved before their safe zone (P1-0 - P1-8)
                        if(p1cPosn == 8)
                        {
                            p1cPosn = 68;
                        }
                        else if(p1cPosn == 7)
                        {
                            p1cPosn = 67;
                        }
                        else if(p1cPosn == 6)
                        {
                            p1cPosn = 66;
                        }
                        else if(p1cPosn == 5)
                        {
                            p1cPosn = 65;
                        }
                        else if(p1cPosn == 4)
                        {
                            p1cPosn = 64;
                        }
                        else if(p1cPosn == 3)
                        {
                            p1cPosn = 63;
                        }
                        else if(p1cPosn == 2)
                        {
                            p1cPosn = 62;
                        }
                        else if(p1cPosn == 1)
                        {
                            p1cPosn = 61;
                        }
                        else if(p1cPosn == 0)
                        {
                            p1cPosn = 60;
                        }
                        cout << pOnePos[p1cPosn] << endl;    //Output modified game board
                        break;
                    case 3:
                        break;
                }
            }

            //Player 2 draws an "8"
            else if(card == 7)
            {
                //Print the card's specific menu
                cout << "You drew an 8!" << endl;
                cout << "1. Move 8 spaces forward" << endl;
                cout << "2. Skip turn" << endl;

                //Check for legal move
                do
                {
                    if((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);                
                } while((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn += 8;
                        if(p2cPosn > 74)
                        {
                            p2cPosn = 74;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 2:
                        break;
                }
            }

            //Player 2 draws a "10"
            else if(card == 8)
            {
                //Print the card's specific menu
                cout << "You drew a 10!" << endl;
                cout << "1. Move 10 spaces forward" << endl;
                cout << "2. Move 1 space backward" << endl;
                cout << "3. Skip turn" << endl;

                //Check for legal move
                do
                {
                    if((pChoice > 3) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn < 9) || (pChoice == 3 && p2cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);                   
                }while((pChoice > 3) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn < 9) || (pChoice == 3 && p2cPosn >= 9));           

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn += 10;
                        if(p2cPosn > 74)
                        {
                            p2cPosn = 74;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 2:
                        p2cPosn -= 1;                        

                        //Determine if Player 2 has moved before their safe zone (P1-0 - P1-8)
                        if(p2cPosn == 8)
                        {
                            p2cPosn = 68;
                        }
                        else if(p2cPosn == 7)
                        {
                            p2cPosn = 67;
                        }
                        else if(p2cPosn == 6)
                        {
                            p2cPosn = 66;
                        }
                        else if(p2cPosn == 5)
                        {
                            p2cPosn = 65;
                        }
                        else if(p2cPosn == 4)
                        {
                            p2cPosn = 64;
                        }
                        else if(p2cPosn == 3)
                        {
                            p2cPosn = 63;
                        }
                        else if(p2cPosn == 2)
                        {
                            p2cPosn = 62;
                        }
                        else if(p2cPosn == 1)
                        {
                            p2cPosn = 61;
                        }
                        else if(p2cPosn == 0)
                        {
                            p2cPosn = 60;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 3:
                        break;
                }
            }

            //Player 2 draws an "11"
            else if(card == 9)
            {
                //Print the card's specific menu
                cout << "You drew an 11!" << endl;
                cout << "1. Move 11 spaces forward" << endl;
                cout << "2. Switch places with an opposing pawn" << endl;
                cout << "3. Skip turn" << endl;

                //Check for legal move 
                do
                {
                    if((pChoice > 3) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn < 9) ||
                      (pChoice == 2 && p1cPosn < 9) || (pChoice == 3 && p2cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);
                } while((pChoice > 3) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn < 9) ||
                       (pChoice == 2 && p1cPosn < 9) || (pChoice == 3 && p2cPosn >= 9));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn += 11;
                        if(p2cPosn > 74)
                        {
                            p2cPosn = 74;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 2:
                        if(p2cPosn >= 15 && p1cPosn >= 15)
                        {
                            temp = p2cPosn;
                            p2cPosn = p1cPosn - 15;
                            p1cPosn = temp + 15;
                        }
                        else if(p2cPosn >= 15 && p1cPosn <= 15)
                        {
                            temp = p2cPosn;
                            p2cPosn = 60 + p1cPosn - 15;
                            p1cPosn = 15 - (60 - temp);
                        }
                        else if(p2cPosn <= 15 && p1cPosn <= 15)
                        {
                            temp = p2cPosn;
                            p2cPosn = 60 + p1cPosn - 15;
                            p1cPosn = temp + 15;
                        }
                        else if(p2cPosn <= 15 && p1cPosn >= 15)
                        {
                            p2cPosn = p1cPosn - 15;
                            p1cPosn = p1cPosn - (p2cPosn - 10);
                        }                       

                        //Determine if Player 2 has moved before their safe zone (P1-0 - P1-8)
                        if(p2cPosn == 8)
                        {
                            p2cPosn = 68;
                        }
                        else if(p2cPosn == 7)
                        {
                            p2cPosn = 67;
                        }
                        else if(p2cPosn == 6)
                        {
                            p2cPosn = 66;
                        }
                        else if(p2cPosn == 5)
                        {
                            p2cPosn = 65;
                        }
                        else if(p2cPosn == 4)
                        {
                            p2cPosn = 64;
                        }
                        else if(p2cPosn == 3)
                        {
                            p2cPosn = 63;
                        }
                        else if(p2cPosn == 2)
                        {
                            p2cPosn = 62;
                        }
                        else if(p2cPosn == 1)
                        {
                            p2cPosn = 61;
                        }
                        else if(p2cPosn == 0)
                        {
                            p2cPosn = 60;
                        }

                        //Determine if Player 1 has moved before their safe zone (P2-0 - P2-8)
                        if(p1cPosn == 8)
                        {
                            p1cPosn = 68;
                        }
                        else if(p1cPosn == 7)
                        {
                            p1cPosn = 67;
                        }
                        else if(p1cPosn == 6)
                        {
                            p1cPosn = 66;
                        }
                        else if(p1cPosn == 5)
                        {
                            p1cPosn = 65;
                        }
                        else if(p1cPosn == 4)
                        {
                            p1cPosn = 64;
                        }
                        else if(p1cPosn == 3)
                        {
                            p1cPosn = 63;
                        }
                        else if(p1cPosn == 2)
                        {
                            p1cPosn = 62;
                        }
                        else if(p1cPosn == 1)
                        {
                            p1cPosn = 61;
                        }
                        else if(p1cPosn == 0)
                        {
                            p1cPosn = 60;
                        }
                        cout << pTwoPos[p2cPosn] << endl;
                        cout << endl;
                        cout << pTwoPos[p1cPosn] << endl;
                        break;
                    case 3:
                        break;
                }
            }

            //Player 2 draws a "12"
            else if(card == 10)
            {
                //Print the card's specific menu
                cout << "You drew a 12!" << endl;
                cout << "1. Move 12 spaces forward" << endl;
                cout << "2. Skip turn" << endl;

                //Check for legal move 
                do
                {
                    if((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);
                } while((pChoice > 2) || (pChoice == 1 && p2cPosn < 9) || (pChoice == 2 && p2cPosn >= 9));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p2cPosn += 12;
                        if(p2cPosn > 74)
                        {
                            p2cPosn = 74;
                        }
                        cout << pTwoPos[p2cPosn] << endl;    //Output modified game board
                        break;
                    case 2:
                        break;
                }
            }      

            //Player 2 draws a "Sorry!" card
            else
            {
                //Print the card's specific menu
                cout << "You drew a \"Sorry!\" Card!" << endl;
                cout << "1. Move an opponent's pawn off the game board!" << endl;
                cout << "2. Skip turn" << endl;

                //Check for legal move 
                do
                {
                    if((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9))
                    {
                        cout << "That's an illegal move!";
                    }
                    cout << "\nWhich choice would you like to make? ";
                    pChoice = int_chk(choice);
                } while((pChoice > 2) || (pChoice == 1 && p1cPosn < 9) || (pChoice == 2 && p1cPosn >= 9));

                //Execute the desired action
                switch(pChoice)
                {
                    case 1:
                        p1cPosn = 0;
                        cout << "\nPlayer 1 has been moved off the game board!" << endl;
                        cout << pTwoPos[0] << endl;
                        break;
                    case 2:
                        break;
                }
            }

            //Determine whether player 2 has won the game
            if(p2cPosn >= 74)
            {
                cout << "\nPlayer 2 has won the game!" << endl;
            }
        }

        //Reset the player's choice
        pChoice = 0;
        cin.clear();
        cin.ignore();          

    //Exit or repeat the while loop
    }
}
