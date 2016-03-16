def caesar(x, message2, abc):
  size=len(message2)
  bool = False
  n=0
  for i in range(size):
    bool = False
    n = 0
    while n < 26 and not bool:
      if message2[i] == abc[n]:
        if (n+x) >= 26:
          r = (n+x) - 26
          message2[i] = abc[r]          
        else:
          message2[i] = abc[n+x]
        bool = True
      n = n + 1

message = "hello world"
message2 = list("hello world")
print("Mensaje original: ", message)
x = 3
abc=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
caesar(x, message2, abc)
print("Mensaje encriptado: ", "".join(message2))
