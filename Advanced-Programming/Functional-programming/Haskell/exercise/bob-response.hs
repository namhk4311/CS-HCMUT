module Bob (responseFor) where

import Data.Char
responseFor :: String -> String
responseFor xs
  | null text = "Fine. Be that way!"
  | isYelling && isAsking = "Calm down, I know what I'm doing!"
  | isYelling = "Whoa, chill out!"
  | isAsking = "Sure."
  | otherwise = "Whatever."
    where 
      text = filter (not . isSpace) xs
      letters = filter (isLetter) xs
      isYelling = all isUpper letters && any isUpper letters
      isAsking = last text == '?'

-- null, isUpper, filter, all, last 