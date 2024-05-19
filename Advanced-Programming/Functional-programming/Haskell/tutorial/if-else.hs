traveltowork :: String -> IO() 
traveltowork weather = do
    if weather == "sunny"
        then putStrLn "walking to work"
        else putStrLn "Driving to work"


main :: IO()
main = do
    traveltowork "sunny"