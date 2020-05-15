import random
def load_members(): #members.txt를 한 줄씩 읽어, 아이디를 키로하는 사전을 만드는 함수
    file = open('members.txt','r',encoding='utf-8')
    members = {}
    for line in file:
        name, passwd, tries, wins, percentage = line.strip('\n').split(',')
        members[name] = (passwd,int(tries),float(wins),float(percentage))
    file.close()
    return members

def store_members(members): #아이디가 키인 사전을 인수로 받아 파일에 쓰는 함수
    file = open('members.txt','w', encoding = 'utf-8')
    names = members.keys()
    for name in names:
        passwd, tries, wins, percentage = members[name]
        line = name + ',' + passwd + ',' + \
               str(tries) + ',' + str(wins) + "," + str(percentage) + '\n'
        file.write(line)
    file.close()

def divide(x,y): # 승률 계산 함수
    return x/y if y > 0 else 0

def login(members): #로그인하기
    username = input("Enter your name: (10 letters max) ")
    while len(username) > 10:
        username = input("Enter your name: (10 letters max) ")
    trypasswd = input("Enter your password: ")
    if username in list(members.keys()):
        if trypasswd == members[username][0]:
            print('You played ' + str(members[username][1]) + ' games and won ' + \
                   str(members[username][2]) + ' of them.')
            print('Your all-time winning percentage is ' + \
                  str(round(100*divide(members[username][2],members[username][1]),1)) + ' %')
            trypasswd, tries, wins, percentage = members[username]
            return username, tries, wins, percentage, members
        else:
            return login(members)
    else:
        members[username] = trypasswd, 0, 0, 0
        return username, 0, 0, 0, members

def show_top5(members): # 승률에 따른 랭킹 보여주기
    print("-----")
    sorted_members = sorted(members.items(), key = lambda x: x[1][3], reverse = True)
    print("All-time Top 5 based on Percentage of Victories")
    count = 1
    for i in sorted_members:
        if count >= 6:
            break
        if int(i[1][1]) >= 5:
            print(str(count) + '. ' + i[0] + ' : '+ str(round(100*float((i[1][3])),1)) +'%')
            count += 1

def fresh_deck(): #새로운 카드 한벌을 섞어서 내준다.
    deck = [2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,\
            10,10,10,10,10,10,10,10,10,11,22,33,44,55,66,76,\
            0,0,0,0,-10,-10,-10,-10,'*2','*2','*2','*2']
    random.shuffle(deck)
    return deck

def hit(deck): #deck을 받아 맨 앞의 카드 1장과 나머지 deck을 내주는 함수. (8-2)
    if deck == []:
        deck = fresh_deck()
    return (deck[0] , deck[1:])

def no_chips(): #칩 개수를 설정하게 하는 함수
    while True:
        try:
            x = int(input('How many chips do you want? (1/3/5) '))
            while x != 1 and x != 3 and x!= 5:
                x = int(input('How many chips do you want? (1/3/5) '))
            break
        except ValueError:
            continue
    chips = x
    return chips

def rsp(): #가위바위보로 누가 먼저 할지 정해준다.x is player, y is computer.
    a = {'r','s','p'}
    x = input('Rock, Paper, Scissors! (r/s/p) ')
    while x not in a:
        x = input('Rock, Paper, Scissors! (r/s/p) ')
    b = ['r','s','p']
    random.shuffle(b)
    r = random.randint(0,2)
    y = b[r]
    while x == y:
        if x == 'r':
            print("You both selected Rock. Draw. Do it again")
        elif x == 's':
            print('You both selected Scissors. Draw. Do it again')
        elif x == 'p':
            print('You both selected Paper. Draw. Do it again.')
        x = input('Rock, Paper, Scissors! (r/s/p) ')
        while x not in a:
            x = input('Rock, Paper, Scissors! (r/s/p) ')
        b = ['r','s','p']
        random.shuffle(b)
        r = random.randint(0,2)
        y = b[r]
        if x != y:
            break
    if x == 'r':
        if y == 's':
            print("Player's pick: Rock\nComputer's pick: Scissors\nYou won. Player will start first.")
            return 'player'
        else:
            print("Player's pick: Rock\nComputer's pick: Paper\nYou lost. Computer will start first.")
            return 'computer'
    elif x == 's':
        if y == 'p':
            print("Player's pick: Scissors\nComputer's pick: Paper\nYou won. Player will start first.")
            return 'player'
        else:
            print("Player's pick: Scissors\nComputer's pick: Rock\nYou lost. Computer will start first.")
            return 'computer'
    elif x == 'p':
        if y == 'r':
            print("Player's pick: Paper\nComputer's pick: Rock\nYou won. Player will start first.")
            return 'player'
        else:
            print("Player's pick: Paper\nComputer's pick: Scissors\nYou lost. Computer will start first.")
            return 'computer'

def card_sum(showed): #낸 카드들의 합을 계산하는 함수.
    count = 0
    for i in showed:
        if i == '*2':
            count = count *2
        else:
            count += int(i)
    return count

def player_select(player,showed):
    #플레이어의 카드와 이미 낸 카드뭉치를 인수로 받아 선택한 카드와 나머지 카드, 낸 카드들의 더미를 튜플로 묶어 리턴한다.
    while True:
        try:
            x = input('What do you want to select? ')
            if x == '*2':
                if x in player:
                    break
            else:
                x = int(x)
                if x in player:
                    break
        except ValueError:
            print('Please type an integer.')
            continue
    player.remove(x)
    showed.append(x)
    return (x,player,showed)

def computer_select(computer,showed):
    #컴퓨터가 카드를 선택하게 하는 함수. 선택한 카드와 나머지 카드, 낸 카드들의 더미를 튜플로 묶어서 리턴한다.
    xs = []
    for i in computer:
        if i == '*2':
            if not ((int(card_sum(showed)) * 2) % 11 == 0 or int(card_sum(showed)) * 2 >= 77):
                xs.append(i)
        else:
            if not ((int(card_sum(showed)) + int(i)) % 11 == 0 or int(card_sum(showed)) + int(i) >= 77):
                xs.append(i)
    if len(xs) != 0:
        random.shuffle(xs)
        computer.remove(xs[0])
        showed.append(xs[0])
        return (xs[0],computer,showed)
    else:
        random.shuffle(computer)
        showed.append(computer[0])
        return (computer[0],computer[1:],showed)

def show_cards(cards): #자신이 가지고 있는 카드를 한 장당 한 줄씩 보여주는 함수.
    print('You have...')
    for i in range(len(cards)):
        if i == len(cards) - 1:
            print(cards[i])
        else:
            print(cards[i], end = ', ')
        
def more(message): #메시지를 보여주고 대답받는 함수. (8-5)
    answer = input(message)
    while not (answer == 'y' or answer == 'n'):
        answer = input(message)
    return answer == 'y'
