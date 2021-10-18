#ifndef ANSWER_H_
#define ANSWER_H_

#include <iostream>
#include <vector>

class Answer
{
    private:
        std::vector<int> answers;

        void checkIndex(const int index) const;
    public:
        Answer();
        Answer(const int count, const int byDefault = -1);

        std::vector<int> getAnswers() const;
        int getAnswer(const int index) const;

        void setAnswers(const std::vector<int> answers);
        void setAnswer(const int answer, const int index);
};

#endif

