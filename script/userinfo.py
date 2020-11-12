import requests

url = "https://uhunt.onlinejudge.org/api/subs-user/1130147"
responses = requests.get(url).json()


class Question:
    def __init__(self, sid, pid, lan, rank):
        self.sid = sid
        self.pid = pid
        self.lan = lan
        self.rank = rank

    def __lt__(self, other):
        if self.pid < other.pid:
            return True
        if self.pid == other.pid and self.rank < other.rank:
            return True
        if self.pid == other.pid and self.rank == other.rank and self.sid < other.sid:
            return True
        return False


    def __str__(self):
        return f"| {self.pid} | {self.rank} | {self.sid} | {self.lan} |\n"

suc = []
fail = []
name = responses["name"]
username = responses["uname"]
tot_sub = len(responses["subs"])


for r in responses["subs"]:
    if r[5] == 5:
        lan = "C++ 11"
    else:
        lan = "Python 3"
    if r[6] == -1:
        fail.append(Question(r[0], r[1], lan, r[6]))
    else:
        suc.append(Question(r[0], r[1], lan, r[6]))


suc.sort()
fail.sort()
readme = open("userInfo.md", "w")

#====================================================================
# Info
readme.write(f"Name : {name}\n")
readme.write(f"Username : {username}\n")
readme.write(f"Total Submission : {tot_sub}\n")
readme.write(f"Successful submission : {len(suc)}\n")
readme.write(f"Unsuccessful submission : {len(fail)}\n")

#====================================================================
# Succesful submission
readme.write("\n### Successful submission\n")
readme.write("|Problem ID | Rank | Submission ID | Language |\n")
readme.write("|:--:|:--:|:--:|:--:|\n")
for q in suc:
    readme.write(q.__str__())

#====================================================================
# Unsuccessful submission
readme.write("### Unsuccessul submission\n")
readme.write("|Problem ID | Rank | Submission ID | Language |\n")
readme.write("|:--:|:--:|:--:|:--:|\n")
for q in fail:
    readme.write(q.__str__())


readme.close()