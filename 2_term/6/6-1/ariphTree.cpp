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

void AriphTree::CreateLeftElement(QChar value)
{
    current->leftElement = new AriphTreeElement(value, current);
}

void AriphTree::CreateRightElement(QChar value)
{
    current->rightElement = new AriphTreeElement(value, current);
}

void AriphTree::DownLeft()
{
    current = current->leftElement;
}

void AriphTree::DownRight()
{
    current = current->rightElement;
}

void AriphTree::Up()
{
    current = current->ancestor;
}

bool AriphTree::IsLeftFree()
{
    return current->leftElement == nullptr;
}

bool AriphTree::IsRightFree()
{
    return current->rightElement == nullptr;
}

void AriphTree::SetDefault()
{
    current = head;
}

int AriphTree::CalculateTree()
{
    return head->Calculate();
}

QChar AriphTree::ValueCurrent()
{
    return current->value;
}

QString AriphTree::PrintTree()
{
    QString stringPrint;
    head->Print(stringPrint);
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

void AriphTree::AriphTreeElement::Print(QString &stringPrint)
{
    if (leftElement != nullptr)
        leftElement->Print(stringPrint);
    stringPrint = stringPrint + value;
    if (rightElement != nullptr)
        rightElement->Print(stringPrint);

}

int AriphTree::AriphTreeElement::Calculate()
{
    if (leftElement == nullptr && rightElement == nullptr)
    {
        return value.toLatin1() - '0';
    }
    switch (value.toLatin1())
    {
    case '+':
    {
        return leftElement->Calculate() + rightElement->Calculate();
    }
    case '-':
    {
        return leftElement->Calculate() - rightElement->Calculate();
    }
    case '*':
    {
        return leftElement->Calculate() * rightElement->Calculate();
    }
    case '/':
    {
        return leftElement->Calculate() / rightElement->Calculate();
    }
    }
    return 0;
}


