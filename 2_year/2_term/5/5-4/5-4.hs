{-use brackets to specify the order of actions-}
main = print $ simpleEq $ derivation ((Const 2 :*: X) :+: (Const 2 :*: X) :+: (Const 2 :**: 3 :*: X))

data Expression =
    Const Int
    | Expression :+: Expression
    | Expression :-: Expression
    | Expression :/: Expression
    | Expression :*: Expression
    | Expression :**: Int
    | X
    deriving (Show, Eq)

derivation :: Expression -> Expression
derivation (exp1 :+: exp2)  = derivation exp1 :+: derivation exp2
derivation (exp1 :-: exp2)  = derivation exp1 :-: derivation exp2
derivation ((Const n) :*: X) = Const n
derivation (exp1 :*: exp2)  = (exp1 :*: derivation exp2) :+: (derivation exp1 :*: exp2)
derivation (exp1 :/: exp2)  = ((derivation exp1 :*: exp2) :-: (exp1 :*: derivation exp2)) :/: (exp2 :*: exp2)
derivation ((Const _) :**: _) = Const 0
derivation (exp1 :**: n) = Const n :*: (exp1 :**: (n - 1))
derivation (Const _) = Const 0
derivation X = Const 1

simple :: Expression -> Expression

simple (Const a :+: Const b) = Const (a + b)
simple (Const a :*: Const b) = Const (a * b)
simple (Const a :-: Const b) = Const (a - b)
simple (Const a :/: Const b) = Const (div a b)
simple (Const 0 :**: _) = Const 0
simple (Const 1 :**: _) = Const 1
simple (Const a :**: b) = Const (a ^ b)

simple (exp1 :*: Const 0) = Const 0
simple (exp1 :*: Const 1) = simple exp1
simple (exp1 :+: Const 0) = simple exp1
simple (exp1 :/: Const 1) = simple exp1
simple (exp1 :-: Const 0) = simple exp1
simple (_ :**: 0) = Const 1
simple (exp1 :**: 1 ) = simple exp1
simple (Const 0 :*: exp1) = Const 0
simple (Const 1 :*: exp1) = simple exp1
simple (Const 0 :+: exp1) = simple exp1
simple (Const 1 :/: exp1) = simple exp1
simple (Const 0 :-: exp1) = simple exp1


simple (exp1 :*: exp2) = simple exp1 :*: simple exp2
simple (exp1 :+: exp2) = simple exp1 :+: simple exp2
simple (exp1 :-: exp2) = simple exp1 :-: simple exp2
simple (exp1 :/: exp2) = simple exp1 :/: simple exp2
simple (exp1 :**: n) = simple exp1 :**: n

simple (Const n) = (Const n)
simple X = X

simpleEq :: Expression -> Expression
simpleEq exp1  = simpleEq' (simple exp1) exp1

simpleEq' :: Expression -> Expression -> Expression
simpleEq' exp1 exp2
        | (exp1 == exp2) = exp1
        | otherwise = simpleEq' (simple exp1) exp1

