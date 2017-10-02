import re;

with open("data.txt") as f:
  content = f.readlines();

content = [x.strip() for x in content]

reduced = []

for line in content:
  match = re.match(r'^\((.*),(.*)\)$', line, re.I);
  if (match):
    reduced.append(match.group(1) + " " + match.group(2))

for i in range(30):
  a = reduced[i]
  b = "" if i + 30 >= len(reduced) else reduced[i + 30]
  c = "" if i + 60 >= len(reduced) else reduced[i + 60]
  d = "" if i + 90 >= len(reduced) else reduced[i + 90]
  print a + "    " + b + "    " + c + "    " + d
