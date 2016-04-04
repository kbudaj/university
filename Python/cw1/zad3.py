def krzyzyk(x):
  lineStars = "*" * x
  lineBlank = " " * x
  for k in range(x):
    print lineBlank + lineStars
  for k in range(x):
    print lineStars * 3
  for k in range(x):
    print lineBlank + lineStars

krzyzyk(4)
