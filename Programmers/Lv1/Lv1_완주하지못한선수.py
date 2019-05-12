def solution(participant, completion):
   participant.sort()
   completion.sort()
   for p, c in zip(participant, completion):
      if p != c:
         return p
   return participant[-1]

participant = ["mislav", "stanko", "mislav", "ana"]
completion = ["stanko", "ana", "mislav"]
print(solution(participant, completion))

