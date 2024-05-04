#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Class to represent a quiz question
class Question {
public:
    string questionText;
    vector<string> options;
    int correctOptionIndex;
};

// Function to shuffle questions randomly
void shuffleQuestions(vector<Question>& questions) {
    srand(time(nullptr));
    for (int i = questions.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(questions[i], questions[j]);
    }
}

// Function to display a question and its options
void displayQuestion(const Question& question) {
    cout << question.questionText << endl;
    for (size_t i = 0; i < question.options.size(); ++i) {
        cout << i + 1 << ". " << question.options[i] << endl;
    }
    cout << endl;
}

// Function to take a quiz
int takeQuiz(const vector<Question>& questions) {
    int score = 0;
    for (const Question& question : questions) {
        displayQuestion(question);
        int selectedOption;
        cout << "Enter your answer (1-" << question.options.size() << "): ";
        cin >> selectedOption;
        if (selectedOption == question.correctOptionIndex + 1) {
            cout << "Correct!" << endl;
            ++score;
        } else {
            cout << "Incorrect!" << endl;
        }
        cout << endl;
    }
    return score;
}

int main() {
    // Sample quiz questions
    vector<Question> quizQuestions = {
        {"What is the capital of India?",
         {"Kolkata", 
         "Mumbai", 
         "New Delhi", 
         "Agra"},
         2 // Index of correct option (Paris)
        },
        {"Who is the author of 'Romeo and Juliet'?",
         {"William Shakespeare", 
         "Charles Dickens", 
         "Jane Austen", 
         "Mark Twain"},
         0 // Index of correct option (William Shakespeare)
        },
        {"What is the chemical symbol for water?",
         {"H2O", 
         "CO2", 
         "O2", 
         "NaCl"},
         0 // Index of correct option (H2O)
        },
        {"What is the capital of France?", 
            {"Paris",
            "London",
            "Berlin",
            "Rome"},
            0
        },
        {  "Who painted the Mona Lisa?", {
            
            "Leonardo da Vinci",
            "Vincent van Gogh",
            "Pablo Picasso",
            "Michelangelo"
            },0

        },
        { "What is the tallest mountain in the world?", {
            
            "Mount Everest",
            "K2",
             "Mount Kilimanjaro",
              "Denali"
            },0

        },
        {   "Who wrote 'To Kill a Mockingbird'?", {
                
                 "J.K. Rowling",
                "Stephen King",
                "Harper Lee",
                "Ernest Hemingway"
             },2


        },
        {  "Which planet is known as the 'Red Planet'?", {
             
             "Venus",
             "Jupiter",
             "Saturn",
             "Mars"
            },3

        }
    };

    shuffleQuestions(quizQuestions); // Shuffle questions randomly

    cout << "Welcome to the Online Quiz!" << endl;
    cout << "----------------------------" << endl;

    int userScore = takeQuiz(quizQuestions);

    cout << "Quiz Complete!" << endl;
    cout << "Your Score: " << userScore << "/" << quizQuestions.size() << endl;

    return 0;
}
