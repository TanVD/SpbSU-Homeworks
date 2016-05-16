import Prelude hiding (id)

data Point = Point { 
    id :: Int,
    wasVisited :: Bool,
    weightPoint :: Int
} deriving Show

instance Eq Point where
 (==) a b = id a == id b

data Edge = Edge {
    from :: Point,
    to :: Point,
    weightEdge :: Int
} deriving (Eq, Show)

data Graph = Graph {
    getPoints ::[Point],
    getEdges :: [Edge]
} deriving Show

data Way = Way [Edge]
{-
let a = Graph [(Point 1 False 0), (Point 2 False 0), (Point 3 False 0)] [(Edge (Point 1 False 0) (Point 2 False 0) 2), (Edge (Point 2 False 0) (Point 3 False 0) 3), (Edge (Point 1 False 0) (Point 3 False 0) 8)] 
let b = [(Point 1 False 0), (Point 2 False 0), (Point 3 False 0)]
-}

dejkstra :: Graph -> Graph
dejkstra (Graph as bs) = dejkstra' (getMin as) (Graph as bs)

dejkstra' :: Point -> Graph -> Graph
dejkstra' (Point 0 True 0) graph = graph
dejkstra' point (Graph points edges) = dejkstra' (getMin (getPoints newGraph)) newGraph
    where newGraph = updateGraph (Graph points edges) point

getMin :: [Point] -> Point
getMin as = getMin' as (-1) (Point 0 True 0)
    where 
        getMin' [] _ point = point
        getMin' (Point pId pWasVisited weight : bs) n point
            | (weight < n || n == (-1)) && not pWasVisited = getMin' bs weight (Point pId pWasVisited weight)
            | otherwise = getMin' bs n point

updateGraph :: Graph -> Point -> Graph
updateGraph (Graph as bs) point = Graph (updatePoints (Graph as bs) point) bs
    
updatePoints :: Graph -> Point -> [Point]
updatePoints (Graph (c:cs) es) point
    | c == point =  Point (id point) True (weightPoint point) : updatePoints (Graph cs es) point
    | not (wasVisited c) = Point (id c) (wasVisited c) (getNewWeight c point es) : updatePoints (Graph cs es) point
    | otherwise =  Point (id c) (wasVisited c) (weightPoint c) : updatePoints (Graph cs es) point
updatePoints (Graph [] _) _ = []

--first where to go, second from where
getNewWeight :: Point -> Point -> [Edge] -> Int
getNewWeight a point (edge:edges)
    | a == from edge && point == to edge =  weightPoint (to edge) + weightEdge edge
    |  a == to edge && point == from edge =  weightPoint (from edge) + weightEdge edge
    |otherwise = getNewWeight a point edges
getNewWeight a _ [] = weightPoint a
