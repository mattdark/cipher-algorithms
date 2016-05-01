def caesar(key, message2, abc):
  size=len(message2)
  bool = False
  n = 0
  x = 0
  for i in range(size):
    bool = False
    n = 0
    while n < 26 and not bool:
      if message2[i] == abc[n]:
        s = n
        bool = True
      n = n + 1
    bool = False
    n = 0
    while n < 26 and not bool:
      if message2[i] != ' ':
        if x == len(key):
          x = 0
        if key[x] == abc[n]:
          t = n + s
          x = x + 1
          bool = True
      n = n + 1
    if message2[i] != ' ':
      if t >= 26:
        r = t - 26
        message2[i] = abc[r]
      else:
        message2[i] = abc[t]

message = "usa software libre"
message2 = list(message)
key = "casa"
print("Mensaje original: ", message)
abc=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
caesar(key, message2, abc)
print("Mensaje encriptado: ", "".join(message2))
