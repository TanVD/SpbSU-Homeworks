import Prelude hiding (id, log)
import Data.List as L
import Control.Monad.Writer.Lazy as W

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
    getPoints ::[Writer [Edge] Point],
    getEdges :: [Edge]
} deriving Show

data Way = Way {
    edges :: [Edge]
} 


instance Show Way where
    show (Way (edge:edges)) = 
        show (id (from edge)) ++
        "->" ++
        show (id (to edge)) ++
        " " ++
        show (Way edges)
    show (Way []) = 
        ""

instance Ord Edge where
  (Edge _ (Point idTo _ _ ) _ ) `compare` (Edge (Point idFrom _ _ ) _ _) =
    idTo `compare` idFrom

{-
let a = Graph [(writer(Point 1 False 0, [])), (writer(Point 2 False 0, [])), (writer(Point 3 False 0, []))][(Edge (Point 1 False 0) (Point 2 False 0) 2), (Edge (Point 2 False 0) (Point 3 False 0) 3), (Edge (Point 1 False 0) (Point 3 False 0) 8)] 
let b = [(writer(Point 1 False 0, [])), (writer(Point 2 False 0, [])), (writer(Point 3 False 0, []))]
-}

printWay :: [Writer [Edge] Point] -> Point -> Way
printWay (writer:as) pointTo 
    | point == pointTo =  Way edge
    | otherwise = printWay as pointTo
    where (point, edge) = runWriter writer
printWay [] pointTo = Way []

dejkstra :: Graph -> Int -> Way
dejkstra (Graph as bs) idEnd =  Way (L.sort (edges (printWay ( (getPoints (dejkstra' start (Graph as bs)))) end)))
    where 
        start = writer (Point 1 False 0, [])
        end = Point idEnd False 0

dejkstra' :: Writer [Edge] Point -> Graph -> Graph
dejkstra' writer graph 
    | point == (Point 0 True 0) = graph 
    | otherwise =  dejkstra' (getMin (getPoints newGraph)) newGraph
    where 
        newGraph = updateGraph graph writer
        (point, _) = runWriter writer


getMin :: [Writer [Edge] Point] -> Writer [Edge] Point
getMin as = getMin' as (-1) (writer(Point 0 True 0, []))
    where 
        getMin' [] _ point = point
        getMin' (writer:bs) n writerMin
            | (weightPoint pointWriter < n || n == (-1)) && not (wasVisited pointWriter) = getMin' bs (weightPoint pointWriter) writer
            | otherwise = getMin' bs n writerMin
            where
                (pointWriter, edgeWriter) = runWriter writer 


updateGraph :: Graph -> Writer [Edge] Point -> Graph
updateGraph (Graph as bs) point = Graph (updatePoints (Graph as bs) point) bs
    
updatePoints :: Graph -> Writer [Edge] Point -> [Writer [Edge] Point]
updatePoints (Graph (writerCur:cs) es) writerMain
    | point == pointMain = writer (Point (id point) True (weightPoint point), edgesMain) : updatePoints (Graph cs es) writerMain
    | not (wasVisited point) && point /= pointMain = updatePoint  writerCur writerMain es
        : updatePoints (Graph cs es) writerMain
    | otherwise =  writerCur : updatePoints (Graph cs es)  writerMain
    where
        (point, edge) = runWriter writerCur
        (pointMain, edgesMain) = runWriter writerMain

updatePoints (Graph [] _) _ = []

updatePoint :: Writer [Edge] Point -> Writer [Edge] Point -> [Edge] -> Writer [Edge] Point
updatePoint  writerOrig writerMain (edge:edges) 
    | point == from edge && pointMain == to edge && ((weightPoint pointMain + weightEdge edge) < weightPoint point || (weightPoint point == 0)) =
       writerMain >>= updateWeight pointMain point edge
    | point == to edge && pointMain == from edge && ((weightPoint pointMain + weightEdge edge) < weightPoint point || (weightPoint point == 0)) = 
       writerMain >>= updateWeight pointMain point edge
    | otherwise = updatePoint writerOrig writerMain edges
    where
        (point, edgesOrig) = runWriter writerOrig
        (pointMain, edgesMain) = runWriter writerMain
updatePoint writerOrig _ [] = writerOrig

updateWeight :: Point -> Point -> Edge -> Point -> Writer [Edge] Point
updateWeight pointMain pointOrig edge _ = writer (Point (id pointOrig) (wasVisited pointOrig) (weightPoint pointMain + weightEdge edge), [edge])

