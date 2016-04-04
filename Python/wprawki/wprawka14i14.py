# 2 wprawki
# https://kno.ii.uni.wroc.pl/ii/pluginfile.php/29619/mod_resource/content/1/wprawka8.pdf

days = {'pn':"Poniedziałek", 'wt':"Wtorek", 'sr':"Środa", 'czw':"Czwartek", 'pi':"Piątek"}
teachers = {}
lessons = []

class Teacher:
    def __init__(self, name):
        self.name = name
        self.lessons = []

    def add_lesson(self, lesson):
        self.lessons.append(lesson)
        lessons.append(lesson)

class Lesson:
    def __init__(self, subject, day, hours, room):
        self.subject = subject
        self.day = day
        self.hours = hours
        self.room = room

    def get_date(self):
        return (self.day, self.hours)

def check_lessons_colisions(teacher):
    t = teachers[teacher]

    for lesson1 in t.lessons:
        l1 = lesson1.get_date()
        for lesson2 in t.lessons:
            l2 = lesson2.get_date()
            if lesson1 != lesson2 and l1[0] == l2[0] and set(l1[1]) & set(l2[1]):
                print("Kolizja na zajeciach: ")
                print("\tNauczyciel: {}".format(t.name))
                print("\tZajecia 1: {}, {} {}".format(l1[0], l1[1], lesson1.subject))
                print("\tZajecia 2: {}, {} {}".format(l2[0], l2[1], lesson2.subject))
                print("")
    return 0

def check_room_collision():
    all_colisions = set()
    n = len(lessons)
    i = 0
    while i < n:
        lesson1 = lessons[i]
        l1 = lesson1.get_date()
        k = i
        while k < n: 
            lesson2 = lessons[k]
            l2 = lesson2.get_date()
            if lesson1 != lesson2 and l1[0] == l2[0] and set(l1[1]) & set(l2[1]) and lesson1.room != None:
                if lesson1.room == lesson2.room:
                    print("Kolizja sali {} w dniu {} godz. {}".format(lesson1.room, days[str(lesson1.day)], lesson1.hours[0]))
                    print("\tZajecia 1: {}".format(lesson1.subject.title()))
                    print("\tZajecia 2: {}".format(lesson2.subject.title()))
                    print("")
            k += 1
        i += 1
   
    return 0
    
    
    
    
"""
def check_room_collision():
    for lesson1 in lessons:
        l1 = lesson1.get_date()
        for lesson2 in lessons:
            l2 = lesson2.get_date()
            if lesson1 != lesson2 and l1[0] == l2[0] and set(l1[1]) & set(l2[1]):
                if lesson1.room == lesson2.room:
                    print("Kolizja sali {} w dniu {} godz. {}".format(lesson1.room, days[str(lesson1.day)], lesson1.hours[0]))
                    print("\tZajecia 1: {}".format(lesson1.subject.title()))
                    print("\tZajecia 2: {}".format(lesson2.subject.title()))
                    print("")
    return 0
"""


def parse(filename):
    schedule = open(filename, 'r')
    schedule = list(filter(None, schedule.read().splitlines()))

    subject = ''

    for line in schedule:
        if len(line.split(',')) >= 3: # Kolejny wpis do tego samego przedmiotu
            elements = line.split(',')
            _day, hours = list(filter(None, elements[0].split(' ')))

            hour_start, hour_end = map(int, hours.split('-'))
            _hours = [h for h in range(hour_start, hour_end)]
            _name = " ".join(list(filter(None, elements[1].split()))).title()

            for a in elements[2].split():
                if a.isdigit():
                    _room = int(a)
                    break
                else:
                    _room = None

            if _name not in teachers: # Brak obiektu o takim imieniu
                teachers[_name] = Teacher(_name)

            t = teachers[_name]
            l = Lesson(_subject, _day, _hours, _room)
            t.add_lesson(l)


            #print(day + ':' + hour_start + "->" + hour_end)
        else: # Nowy przedmiot
            _subject = line

parse('schedule.txt')

# Wprawka 1 Kolizje Lekcji
for t in teachers:
    check_lessons_colisions(t)

# Wprawka 2 Kolizje sal
#check_room_collision()
