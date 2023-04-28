#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "Game.h"

int main() {
    //Init srand
    srand(static_cast<unsigned>(time(NULL)));

    //Get player name.
    std::cout << "Podaj swoje imię.\n";
    std::string name;
    std::cin>>name;

    //get file with quests.
    std::ifstream file("questionspl.csv");

    bool isWordSavedForBillGates = true;

    //next game sitting
    std::string row;
    while (getline(file, row)) {
        std::string questionId;
        std::string question, correctAnswer;
        std::string answers[4];
        std::string *pAnswers = answers;

        //showing game questions and answers.
        std::stringstream stringStream(row);
        std::getline(stringStream, questionId, ';');
        std::getline(stringStream, question, ';');
        std::getline(stringStream, *pAnswers, ';');
        std::getline(stringStream, *(pAnswers + 1), ';');
        std::getline(stringStream, *(pAnswers + 2), ';');
        std::getline(stringStream, *(pAnswers + 3), ';');
        std::getline(stringStream, correctAnswer, ';');
        std::cout << questionId << ". " << question << "\n1) " << *answers << "\n2) " << *(answers + 1) << "\n3) "
                  << *(pAnswers + 2) << "\n4)" << *(pAnswers + 3);

        //catch answer
        int answer;
        std::cin >> answer;
        system("cls");
        system("clear");
        //Tux survive or die.
        if (*(answers + answer - 1) == correctAnswer) {
            std::cout
                    << " udał ci się poprawnie odpowiedzieć nadal żyjesz. Do zobaczenia w kolejnej rundzie\n\n\n\n";
        } else {
            Game game;
            while (game.isRunning()){

                //Update
                game.update();

                //Render
                game.render();
            }
            isWordSavedForBillGates = game.isTuxSurvive();
            break;
        }
    }
    file.close();

    //win
    if (isWordSavedForBillGates){
        system("cls");
        system("clear");
        std::cout << "Brawo " << name << ", udało ci się ocalić świat przed złym wrednym Billem Gatesem.\n";
    } else{
        std::cout
                << "Jak by to delikatnie powiedzieć?\nO już wiem.\nTux przestał przypominać siebie!\nDoprowadziłeś do jego śmierci.\nRuch oporu przeciwko Bilowi Gatesowi i jego planom na zniewolenie świata. Upadł, ponieważ zabiłeś jego przywódcę\nTeraz nik go już nie powstrzyma wszyscy skończymy jako jego niewolnicy.";
    }
    return 0;
}
