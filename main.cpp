// Libraries Used
#include <iostream>
#include <iomanip>

using namespace std;

//! Enums System
// used for selecting and organizing :
// State (win or loss)
// Round and Game Level (easy - medium - hard - mix)
// Opertion type (addittion - substraction - multiplication - division - mixed)
enum enRoundState
{
    win = 1,
    loss = 0
};
enum enLevel
{
    easy = 1,
    meduim = 2,
    hard = 3,
    mix = 4
};
enum enOperationtype
{

    addition = 1,
    substraction = 2,
    multiplication = 3,
    division = 4,
    mixed = 5
};

//! Structs Ststem (round - game)
struct stRoundInfo
{

    int RoundNumber;
    enLevel RoundLevel;

    int Num1;

    enOperationtype Operation;
    char OperationCharacter;

    int Num2;

    float PlayerAnswer;
    float RightAnswer;
};
struct stGameInfo
{

    int Rounds;
    int RightAnswers = 0;
    int WrongAnwers = 0;

    string GameLevelString;
    enLevel GameLevel;

    enOperationtype OperationType;
    string OperationString;

    string FinalResult;
};

//* Random Generation Function
int RandomNumber(int From, int To)
{

    return rand() % (To - From + 1) + From;
}

//* Input Reading Function
int ReadRounds()
{

    int rounds;

    do
    {

        cout << "How Many Rounds You Want To Play ?" << endl
             << "Your Choice: ";

        cin >> rounds;

        cout << endl;

    } while (rounds < 0);

    return rounds;
}
enOperationtype ReadOperationType()
{

    int choice;

    do
    {
        cout << "What operation do you want ?" << endl
             << "(1)Addition (2)Substraction (3)Multiplication (4)Division (5)Mix" << endl
             << "Your choice: ";

        cin >> choice;

        cout << endl;

    } while (choice < 1 || choice > 5);

    return static_cast<enOperationtype>(choice);
}
enLevel ReadGameDificulty()
{

    int choice;

    do
    {

        cout << "Enter The Level:" << endl
             << "(1) Easy (2) Meduim (3) Hard (4) Mixed" << endl
             << "Your Choice: ";

        cin >> choice;

        cout << endl;

    } while (choice < 1 || choice > 4);

    return static_cast<enLevel>(choice);
}
float ReadNumber()
{

    float num;
    cin >> num;

    cout << endl;

    return num;
}

//* Store chars & strings Functions
// Made for turning enums to chars and strings
char StoreRoundOperationCharacter(enOperationtype operation)
{

    switch (operation)
    {
    case enOperationtype::addition:

        return '+';
        break;

    case enOperationtype::substraction:

        return '-';
        break;

    case enOperationtype::multiplication:

        return '*';
        break;

    case enOperationtype::division:

        return '/';
        break;
    }
}
string StoreDifficulty(enLevel GameDifficulty)
{

    switch (GameDifficulty)
    {
    case enLevel::easy:

        return "Easy";
        break;

    case enLevel::meduim:

        return "Meduim";
        break;

    case enLevel::hard:

        return "Hard";
        break;

    case enLevel::mix:

        return "Mix";
        break;
    }
}
string StoreGameOperationString(enOperationtype GameOperationType)
{

    switch (GameOperationType)
    {
    case enOperationtype::addition:

        return "Addition";

        break;

    case enOperationtype::substraction:

        return "Substraction";

        break;
    case enOperationtype::multiplication:

        return "Multiplication";

        break;
    case enOperationtype::division:

        return "Division";

        break;

    case enOperationtype::mixed:

        return "Mixed";

        break;
    }
}

//! Answer Calculator Function
float AnswerCalc(float num1, float num2, enOperationtype operation)
{

    switch (operation)
    {
    case enOperationtype::addition:

        return (num1 + num2);

        break;

    case enOperationtype::substraction:

        return (num1 - num2);

        break;
    case enOperationtype::multiplication:

        return (num1 * num2);

        break;
    case enOperationtype::division:

        return (num1 / num2);

        break;
    }
}

//! Level Functions
void EasyLevel(stRoundInfo &RoundInfo)
{

    RoundInfo.Num1 = RandomNumber(-10, 10);
    RoundInfo.Num2 = RandomNumber(-10, 10);

    RoundInfo.RightAnswer = AnswerCalc(RoundInfo.Num1, RoundInfo.Num2, RoundInfo.Operation);
}
void MeduimLevel(stRoundInfo &RoundInfo)
{

    RoundInfo.Num1 = RandomNumber(-50, 50);
    RoundInfo.Num2 = RandomNumber(-50, 50);

    RoundInfo.RightAnswer = AnswerCalc(RoundInfo.Num1, RoundInfo.Num2, RoundInfo.Operation);
}
void HardLevel(stRoundInfo &RoundInfo)
{

    RoundInfo.Num1 = RandomNumber(-100, 100);
    RoundInfo.Num2 = RandomNumber(-100, 100);

    RoundInfo.RightAnswer = AnswerCalc(RoundInfo.Num1, RoundInfo.Num2, RoundInfo.Operation);
}
void MixLevel(stRoundInfo &RoundInfo)
{

    enLevel RandomLevel;
    RandomLevel = static_cast<enLevel>(RandomNumber(1, 3));

    switch (RandomLevel)
    {
    case enLevel::easy:

        EasyLevel(RoundInfo);
        break;

    case enLevel::meduim:

        MeduimLevel(RoundInfo);
        break;

    case enLevel::hard:

        HardLevel(RoundInfo);
        break;
    }
}

//* Selector Functions
// To select each round level and operation based on GameInfo
void LevelSelector(enLevel Gamelevel, stRoundInfo &RoundInfo)
{

    switch (Gamelevel)
    {
    case enLevel::easy:

        EasyLevel(RoundInfo);
        break;

    case enLevel::meduim:

        MeduimLevel(RoundInfo);
        break;

    case enLevel::hard:

        HardLevel(RoundInfo);
        break;

    case enLevel::mix:

        MixLevel(RoundInfo);
        break;
    }
}
enOperationtype RoundOpratoinSelector(enOperationtype GameOpeationType)
{

    switch (GameOpeationType)
    {
    case enOperationtype::addition:

        return enOperationtype::addition;

        break;

    case enOperationtype::substraction:

        return enOperationtype::substraction;

        break;
    case enOperationtype::multiplication:

        return enOperationtype::multiplication;

        break;
    case enOperationtype::division:

        return enOperationtype::division;

        break;

    case enOperationtype::mixed:

        RoundOpratoinSelector(static_cast<enOperationtype>(RandomNumber(1, 4)));

        break;
    }
}

//* Check Functions
// AnswerCheck : to compare between answers and print wether true or false
// ReplayCheck : ask for raplaying the game
bool AnswerCheck(float PlayerAnswer, float RightAnswer)
{

    if (PlayerAnswer == RightAnswer)
    {

        cout << "\033[42m" << " Your Answer Is Right " << "\033[0m" << endl;
        cout << "====================================================" << endl;

        return true;
    }
    else
    {

        cout << "\033[41m" << "\aWrong Answer. The Right Answer is " << RightAnswer << "\033[0m" << endl;
        cout << "====================================================" << endl;

        return false;
    }
}
bool ReplayCheck()
{

    char choice;

    do
    {

        cout << "Do you want to play Again ? (Y)Yes (N)No" << endl
             << "Your Choice: ";

        cin >> choice;

    } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    if (choice == 'y' || choice == 'Y')
        return true;

    else
        return false;
}

//! Screen Functions
void GameStartScreen()
{

    cout << "====================================================" << endl
         << "              Welcome to The MATH quiz              " << endl
         << "====================================================" << endl;
}
void RoundScreen(stRoundInfo &RoundInfo)
{

    cout << "====================================================" << endl
         << " Question " << RoundInfo.RoundNumber << endl
         << endl
         << RoundInfo.Num1 << " " << RoundInfo.OperationCharacter << " " << RoundInfo.Num2 << " = ";

    RoundInfo.PlayerAnswer = ReadNumber();
}
void GameOverScreen(stGameInfo GameInfo)
{

    string TextColor = "";
    string ColorEnd = "\033[0m";
    GameInfo.FinalResult;

    if (GameInfo.RightAnswers >= GameInfo.WrongAnwers)
    {

        TextColor = "\033[42m"; // Green
        GameInfo.FinalResult = "Win";
    }
    if (GameInfo.RightAnswers < GameInfo.WrongAnwers)
    {

        TextColor = "\033[41m"; // Red
        GameInfo.FinalResult = "Lost";
    }

    cout << endl;

    cout << TextColor << "=====================================================" << ColorEnd << endl
         << TextColor << setw(53) << " " << ColorEnd << endl
         << TextColor << "            + + + G A M E   O V E R + + +            " << ColorEnd << endl
         << TextColor << setw(53) << " " << ColorEnd << endl
         << TextColor << "=====================================================" << ColorEnd << endl
         << TextColor << setw(26) << right << "You " << setw(27) << left << GameInfo.FinalResult << ColorEnd << endl
         << TextColor << "=====================================================" << ColorEnd << endl
         << TextColor << setw(53) << " " << ColorEnd << endl
         << TextColor << setw(16) << left << "Game Rounds" << " : " << setw(34) << left << GameInfo.Rounds << ColorEnd << endl
         << TextColor << setw(16) << "GameLevelString" << " : " << setw(34) << left << GameInfo.GameLevelString << ColorEnd << endl
         << TextColor << setw(16) << "Operation Type" << " : " << setw(34) << left << GameInfo.OperationString << ColorEnd << endl
         << TextColor << setw(16) << "Right Answers" << " : " << setw(34) << left << GameInfo.RightAnswers << ColorEnd << endl
         << TextColor << setw(16) << "Wrong Answers" << " : " << setw(34) << left << GameInfo.WrongAnwers << ColorEnd << endl
         << TextColor << setw(53) << " " << ColorEnd << endl
         << TextColor << "=====================================================" << ColorEnd << endl;

    cout << endl;
}

//* Helper Functions
void ClearScreen()
{

    cout << "\033[2J\033[H";
}
void Thanks()
{

    cout << "\n";
    cout << "=====================================================" << endl
         << "                Thank You For Playing                " << endl
         << "             Made By: Eng.Youssef Mousad             " << endl
         << "=====================================================" << endl;
    cout << "\n";
}

//! Main Game Function
void StartGame()
{

    int Rounds;

    stRoundInfo RoundInfo;
    stGameInfo GameInfo;

    do
    {

        ClearScreen();

        GameStartScreen();

        Rounds = ReadRounds();
        GameInfo.Rounds = Rounds;

        if (Rounds == 0)
            goto EndGame;

        GameInfo.GameLevel = ReadGameDificulty();
        GameInfo.GameLevelString = StoreDifficulty(GameInfo.GameLevel);

        GameInfo.OperationType = ReadOperationType();
        GameInfo.OperationString = StoreGameOperationString(GameInfo.OperationType);

        for (RoundInfo.RoundNumber = 1; RoundInfo.RoundNumber <= Rounds; RoundInfo.RoundNumber++)
        {

            RoundInfo.Operation = RoundOpratoinSelector(GameInfo.OperationType);
            RoundInfo.OperationCharacter = StoreRoundOperationCharacter(RoundInfo.Operation);

            LevelSelector(GameInfo.GameLevel, RoundInfo);

            RoundInfo.RightAnswer = AnswerCalc(RoundInfo.Num1, RoundInfo.Num2, RoundInfo.Operation);

            RoundScreen(RoundInfo);

            if (AnswerCheck(RoundInfo.PlayerAnswer, RoundInfo.RightAnswer))
            {
                GameInfo.RightAnswers++;
            }
            else
            {
                GameInfo.WrongAnwers++;
            }
        }

        GameOverScreen(GameInfo);

        GameInfo.RightAnswers = 0;
        GameInfo.WrongAnwers = 0;

    EndGame:;

    } while (ReplayCheck());

    Thanks();
}

//* Code Main Function
int main()
{

    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}
