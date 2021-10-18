#include "Answer.h"

void Answer::checkIndex(const int index) const
{
    if ((index < 0) || (index >= answers.size()))
    {
        throw -1;
    }
}

Answer::Answer() { }

Answer::Answer(const int count, const int byDefault)
{
    if (count <= 0)
    {
        throw -1;
    }

    for (int i = 0; i < count; i++)
    {
        answers.push_back(byDefault);
    }
}

std::vector<int> Answer::getAnswers() const
{
    return answers;
}

int Answer::getAnswer(const int index) const
{
    checkIndex(index);
    return answers[index];
}

void Answer::setAnswers(const std::vector<int> answers)
{
    this->answers = answers;
}

void Answer::setAnswer(const int answer, const int index)
{
    checkIndex(index);

    answers[index] = answer;
}

