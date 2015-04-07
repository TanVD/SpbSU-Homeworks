#include "ariphTree.h"

AriphTree::AriphTree(QChar value)
{
    head = new AriphTreeElement(value, nullptr);
    current = head;
}

AriphTree::~AriphTree()
{
    if (head != nullptr)
    {
        delete head;
    }
}

void AriphTree::createLeftElement(QChar value)
{
    current->leftElement = new AriphTreeElement(value, current);
}

void AriphTree::createRightElement(QChar value)
{
    current->rightElement = new AriphTreeElement(value, current);
}

void AriphTree::moveToLeftChild()
{
    current = current->leftElement;
}

void AriphTree::moveToRightChild()
{
    current = current->rightElement;
}

void AriphTree::up()
{
    current = current->ancestor;
}

bool AriphTree::isLeftFree()
{
    return current->leftElement == nullptr;
}

bool AriphTree::isRightFree()
{
    return current->rightElement == nullptr;
}

void AriphTree::setDefault()
{
    current = head;
}

int AriphTree::calculateTree()
{
    return head->calculate();
}

QChar AriphTree::valueCurrent()
{
    return current->value;
}

QString AriphTree::printTree()
{
    QString stringPrint;
    head->print(stringPrint);
    return stringPrint;
}

AriphTree::AriphTreeElement::AriphTreeElement(QChar value, AriphTree::AriphTreeElement *ancestor)
{
    this->value = value;
    leftElement = nullptr;
    rightElement = nullptr;
    this->ancestor = ancestor;
}

AriphTree::AriphTreeElement::~AriphTreeElement()
{
    if (leftElement != nullptr)
    {
        delete leftElement;
    }
    if (leftElement != nullptr)
    {
        delete rightElement;
    }
}

void AriphTree::AriphTreeElement::print(QString &stringPrint)
{
    if (leftElement != nullptr)
        leftElement->print(stringPrint);
    stringPrint = stringPrint + value;
    if (rightElement != nullptr)
        rightElement->print(stringPrint);

}

int AriphTree::AriphTreeElement::calculate()
{
    if (leftElement == nullptr && rightElement == nullptr)
    {
        return value.toLatin1() - '0';
    }
    switch (value.toLatin1())
    {
    case '+':
    {
        return leftElement->calculate() + rightElement->calculate();
    }
    case '-':
    {
        return leftElement->calculate() - rightElement->calculate();
    }
    case '*':
    {
        return leftElement->calculate() * rightElement->calculate();
    }
    case '/':
    {
        return leftElement->calculate() / rightElement->calculate();
    }
    }
    return 0;
}


