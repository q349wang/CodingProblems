# Write any import statements here

def oneway(N: int, C: str, X: int, Y: int) -> int:
  # Write your code here
  
  PA_pairs = [0 for i in range(0, N)]
  AB_pairs = [0 for i in range(0, N)]
  
  num = 0
  Ps = 0
  for i in range(0, N):
    if i >= X:
      if C[i - X] == 'P':
        Ps += 1
      
    if i >= Y + 1:
      if C[i - Y - 1] == 'P':
        Ps -= 1

    if C[i] == 'A':
      PA_pairs[i] = Ps
  
  rev_C = C[::-1]
  
  Bs = 0
  for i in range(0, N):
    if i >= X:
      if rev_C[i - X] == 'B':
        Bs += 1
      
    if i >= Y + 1:
      if rev_C[i - Y - 1] == 'B':
        Bs -= 1

    if rev_C[i] == 'A':
      AB_pairs[N - i - 1] = Bs
  
  for i in range(0, N):
    num += PA_pairs[i] * AB_pairs[i]
  
  return num

def getArtisticPhotographCount(N: int, C: str, X: int, Y: int) -> int:
  # Write your code here
  
  num = 0
  
  num += oneway(N, C, X, Y)
  
  num += oneway(N, C[::-1], X, Y)
  
  return num
