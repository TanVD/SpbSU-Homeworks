import Prelude hiding (id)

data Point = Point { 
    id :: Int,
    wasVisited :: Bool,
    weightPoint :: Int,
    way :: [Edge]
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

data Way = Way {
    edges :: [Edge]
} deriving Show
{-
let a = Graph [(Point 1 False (0) []), (Point 2 False (0) []), (Point 3 False (0) [])] [(Edge (Point 1 False 0 []) (Point 2 False 0 []) 2), (Edge (Point 2 False 0 []) (Point 3 False 0 []) 3), (Edge (Point 1 False 0 []) (Point 3 False 0 []) 8)] 
let b = [(Point 1 False 0 []), (Point 2 False 0 []), (Point 3 False 0 [])]
-}

printWay :: [Point] -> Point -> Way
printWay (a:as) point 
    | a == point =  Way (way a)
    | otherwise = printWay as point
printWay [] point = Way []

dejkstra :: Graph -> Int -> Way
dejkstra (Graph as bs) idEnd = printWay (getPoints (dejkstra' start (Graph as bs))) end
    where 
        start = (Point 1 False (0) [])
        end = Point idEnd False 0 []

dejkstra' :: Point -> Graph -> Graph
dejkstra' (Point 0 True 0 []) graph = graph
dejkstra' point (Graph points edges) = dejkstra' (getMin (getPoints newGraph)) newGraph
    where newGraph = updateGraph (Graph points edges) point

getMin :: [Point] -> Point
getMin as = getMin' as (-1) (Point 0 True 0 [])
    where 
        getMin' [] _ point = point
        getMin' (Point pId pWasVisited weight pWay : bs) n point
            | (weight < n || n == (-1)) && not pWasVisited = getMin' bs weight (Point pId pWasVisited weight pWay)
            | otherwise = getMin' bs n point

updateGraph :: Graph -> Point -> Graph
updateGraph (Graph as bs) point = Graph (updatePoints (Graph as bs) point) bs
    
updatePoints :: Graph -> Point -> [Point]
updatePoints (Graph (c:cs) es) point
    | c == point =  Point (id point) True (weightPoint point) (way point) : updatePoints (Graph cs es) point
    | not (wasVisited c) && c /= point = Point (id c) (wasVisited c)  (fst updatedWeight) (snd updatedWeight) : updatePoints (Graph cs es) point
    | otherwise =  Point (id c) (wasVisited c) (weightPoint c) (way c) : updatePoints (Graph cs es) point
    where
        updatedWeight = updateWeight c point es
updatePoints (Graph [] _) _ = []

--first where to go, second from where
updateWeight :: Point -> Point -> [Edge] -> (Int, [Edge])
updateWeight a point (edge:edges) 
    | a == from edge && point == to edge && ((weightPoint point + weightEdge edge) < weightPoint a || (weightPoint a == (0))) =
      (weightPoint point + weightEdge edge, (edge : (way point)))
    | a == to edge && point == from edge && ((weightPoint point + weightEdge edge) < weightPoint a || (weightPoint a == (0))) = 
      (weightPoint point + weightEdge edge, (edge : (way point)))
    | otherwise = updateWeight a point edges
updateWeight a _ [] = (weightPoint a, way a)