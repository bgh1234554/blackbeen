from lobo import *
import random
def lobo77():
    print('Welcome to Lobo77 game!')
    username, tries, wins, percentage, members = login(load_members())
    trypasswd = members[username][0]
    game = 1
    win = 0
    print('-----')
    deck = fresh_deck() #로보 77 덱
    computer = [] #컴퓨터가 가지고 있는 카드
    player = [] # 플레이어가 가지고 있는 카드
    showed = [] #각자 낸 카드들의 모음
    chips = 0
    ComChips = 0
    for _ in range(5):
        card, deck = hit(deck) # 1장 뽑아서
        player.append(card) # 손님에게 주고
        card, deck = hit(deck) # 1장 뽑아서
        computer.append(card) # 딜러에게 준다. 이를 5회 반복한다.
    chips = no_chips()
    ComChips = chips
    first = rsp()
    game_round = 1
    turn = 1
    if first == 'computer': #컴퓨터가 먼저 시작할 경우
        print('-----')
        com_select , computer, showed = computer_select(computer, showed)
        print('computer selected',com_select)
        computer.append(deck[0])
        deck.remove(deck[0])
        sum_showed = card_sum(showed)
        print('total sum is',sum_showed)
    while True:
        if (game_round > 1 and turn == 1) or (game > 1 and game_round == 1 and turn == 1):
                deck = fresh_deck() #로보 77 덱
                computer = [] #컴퓨터가 가지고 있는 카드
                player = [] # 플레이어가 가지고 있는 카드
                showed = [] #각자 낸 카드들의 모음
                for _ in range(5):
                    card, deck = hit(deck) # 1장 뽑아서
                    player.append(card) # 손님에게 주고
                    card, deck = hit(deck) # 1장 뽑아서
                    computer.append(card) # 딜러에게 준다. 이를 5회 반복한다.
                if game > 1 and game_round == 1 and turn == 1: #새판 시작시
                    #칩 개수 다시 물어보기
                    chips = no_chips()
                    ComChips = chips
                first = rsp()
                if first == 'computer': #새로운 라운드에서 컴퓨터가 먼저 시작할 경우
                    print('-----')
                    com_select , computer, showed = computer_select(computer, showed)
                    print('computer selected',com_select)
                    computer.append(deck[0])
                    deck.remove(deck[0])
                    sum_showed = card_sum(showed)
                    print('total sum is',sum_showed)
        print('-----')
        print("Now, player's turn.")
        show_cards(player)
        play_select, player, showed = player_select(player, showed)
        if card_sum(showed) > 76:
            chips -= 1
            print('The Sum of cards is over 76!')
            print('Now you have',chips,'chips.')
            if chips >= 0:
                print('Generating New Round...')
                game_round += 1
                turn = 1
                continue
        elif card_sum(showed) % 11 == 0 and card_sum(showed) > 0:
            chips -= 1
            print('Sum of cards is the multiple of 11.\n so your number of chip is',chips)
        else:
            while True:
                try:
                    ans = input("Tell your sum ")
                    if isinstance(int(ans),int) == True:
                        break
                except ValueError as e:
                    print(e,'is not an integer. Please type an integer.')
                    continue
            if card_sum(showed) != int(ans):
                chips -= 1
                print('You are wrong, correct answer is',card_sum(showed))
                print('so your number of chip is',chips)
        if chips < 0:
            print("You lose..")
            ask = more("Do you want to play more? (y/n) ")
            if ask == True:
                game += 1
                game_round = 1
                turn = 1
                continue
            else:
                break
        print('-----')
        print("Now, computer's turn")
        player.append(deck[0])
        deck.remove(deck[0])
        com_select, computer, showed = computer_select(computer, showed)
        print('computer selected',com_select)
        computer.append(deck[0])
        deck.remove(deck[0])
        if card_sum(showed) > 76:
            ComChips -= 1
            print('The sum of card is over 76!')
            print('Now computer has',ComChips,'chips.')
            if ComChips >= 0:
                print('Generating New Round...')
                game_round += 1
                turn = 1
                continue
        elif card_sum(showed) % 11 == 0 and card_sum(showed) > 0:
            ComChips -= 1
            print('Computer used wrong card, so computer lose a chip.')
            print('Now computer has',ComChips,'chips')
        computer.append(deck[0])
        deck.remove(deck[0])
        turn += 1
        if len(deck) == 0:
            deck = showed[:-1]
            random.shuffle(deck)
        if ComChips<0:
            print("You Win!")
            ask = more("Do you want to play more? (y/n) ")
            if ask == True:
                game += 1
                win += 1
                game_round = 1
                turn = 1
                continue
            else:
                win+=1
                break
    tries += game
    wins += win
    percentage = divide(wins,tries)
    members[username] = trypasswd, tries, wins, percentage
    store_members(members)
    print('\n-----')
    print('You played', game, 'games and won',win,'of them.')
    print('Your winning percentage today is' , round(100*float(divide(win,game)),1), "%")
    show_top5(members)
    print('Bye!')
lobo77()