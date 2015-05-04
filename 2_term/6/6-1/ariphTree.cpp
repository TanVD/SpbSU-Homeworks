#include "ariphTree.h"

AriphTree::AriphTree(QChar value)
{
    head = chooseChild(value, nullptr);
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
    current->leftElement = chooseChild(value, current);
}

void AriphTree::createRightElement(QChar value)
{
    current->rightElement = chooseChild(value, current);
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

AriphTree::AriphTreeElement *AriphTree::chooseChild(QChar value, AriphTree::AriphTreeElement *ancestor)
{
    if (value.isDigit())
        return new AriphTreeElementDigit(value, ancestor);
    switch (value.toLatin1())
    {
    case '+':
    {
        return new AriphTreeElementPlus(value, ancestor);
    }
    case '-':
    {
        return new AriphTreeElementMinus(value, ancestor);
    }
    case '*':
    {
        return new AriphTreeElementMultiply(value, ancestor);
    }
    case '/':
    {
        return new AriphTreeElementDivide(value, ancestor);
    }
    }
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

int AriphTree::AriphTreeElementPlus::calculate()
{
    return leftElement->calculate() + rightElement->calculate();
}

int AriphTree::AriphTreeElementMultiply::calculate()
{
    return leftElement->calculate() * rightElement->calculate();

}

int AriphTree::AriphTreeElementMinus::calculate()
{
    return leftElement->calculate() - rightElement->calculate();
}

int AriphTree::AriphTreeElementDivide::calculate()
{
    return leftElement->calculate() / rightElement->calculate();

}

int AriphTree::AriphTreeElementDigit::calculate()
{
    return value.toLatin1() - '0';
}
