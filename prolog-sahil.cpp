% Defining males and females
% Defining genders
female(jijabai).
female(kanchan).
female(shobha).
female(sunayana).
female(dhondabai).
female(malati).
female(pooja).
female(reva).
female(jaya).
female(saumya).
female(nanda).
female(swati).
female(sumana).
female(jyoti).
female(samruddhi).
female(mangal).
female(prajakta).
female(swara).
female(laxmi).
female(sheetal).
female(priyanka).
female(shraddha).
female(vidya).
female(savitri).
female(shantabai).


male(dattatraya).
male(baisaheb).
male(uttam).
male(gajanan).
male(vishwanath).
male(aniket).
male(appasaheb).
male(rajkumar).
male(dhanu).
male(vishwajeet).
male(shree).
male(shivansh).
male(prince).
male(sudhakar).
male(prabhakar).
male(amar).
male(sahil).   % user
male(samarth).
male(shivling).
male(madhukar).
male(shantinath).
male(shivam).
male(bhausaheb).
male(sachin).
male(pandurang).
male(sunil).
male(saurabh).
male(anil).
male(dhondiba).

% Paternal Side

% Dattatraya and Jijabai's children
parent(dattatraya, baisaheb).
parent(jijabai, baisaheb).
parent(dattatraya, gajanan).
parent(jijabai, gajanan).
parent(dattatraya, appasaheb).
parent(jijabai, appasaheb).
parent(dattatraya, prabhakar).
parent(jijabai, prabhakar).

% Gajanan and Kanchan's children
parent(gajanan, shobha).
parent(kanchan, shobha).
parent(gajanan, vishwanath).
parent(kanchan, vishwanath).

% Vishwanath and Sunayana's child
parent(vishwanath, aniket).
parent(sunayana, aniket).

% Appasaheb and Dhondabai's children
parent(appasaheb, rajkumar).
parent(dhondabai, rajkumar).
parent(appasaheb, jaya).
parent(dhondabai, jaya).

% Rajkumar and Malati's children
parent(rajkumar, dhanu).
parent(malati, dhanu).
parent(rajkumar, vishwajeet).
parent(malati, vishwajeet).
parent(rajkumar, pooja).
parent(malati, pooja).

% Pooja and Shree's children
parent(shree, shivansh).
parent(pooja, shivansh).
parent(shree, reva).
parent(pooja, reva).

% Jaya and Sudhakar's children
parent(sudhakar, prince).
parent(jaya, prince).
parent(sudhakar, saumya).
parent(jaya, saumya).

% Prabhakar and Nanda's children
parent(prabhakar, amar).
parent(nanda, amar).

% Amar and Swati's children
parent(amar, sahil).    % User
parent(swati, sahil).
parent(amar, samarth).
parent(swati, samarth).

% Maternal Side

% Shivling and Shantabai's children
parent(shivling, madhukar).
parent(shantabai, madhukar).
parent(shivling, bhausaheb).
parent(shantabai, bhausaheb).
parent(shivling, pandurang).
parent(shantabai, pandurang).
parent(shivling, savitri).
parent(shantabai, savitri).

% Madhukar and Suman's children
parent(madhukar, swati).
parent(sumana, swati).
parent(madhukar, shantinath).
parent(sumana, shantinath).

% Swati and Amar's children
parent(swati, sahil).   % User
parent(amar, sahil).
parent(swati, samarth).
parent(amar, samarth).

% Shantinath and Jyoti's children
parent(shantinath, shivam).
parent(jyoti, shivam).
parent(shantinath, samruddhi).
parent(jyoti, samruddhi).

% Bhausaheb and Mangal's child
parent(bhausaheb, sachin).
parent(mangal, sachin).

% Sachin and Prajakta's child
parent(sachin, swara).
parent(prajakta, swara).

% Pandurang and Laxmi's children
parent(pandurang, sunil).
parent(laxmi, sunil).
parent(pandurang, anil).
parent(laxmi, anil).

% Sunil and Sheetal's children
parent(sunil, saurabh).
parent(sheetal, saurabh).
parent(sunil, shraddha).
parent(sheetal, shraddha).

% Saurabh and Priyanka's child
parent(saurabh, shivangi).
parent(priyanka, shivangi).

% Basic family relationships
father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).
child(X, Y) :- parent(Y, X).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), sibling(X, Y).
sister(X, Y) :- female(X), sibling(X, Y).
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
grandfather(X, Y) :- male(X), grandparent(X, Y).
grandmother(X, Y) :- female(X), grandparent(X, Y).
wife(X, Y) :- female(X), male(Y), parent(X, Z), parent(Y, Z).
husband(X, Y) :- male(X), female(Y), parent(X, Z), parent(Y, Z).
niece(X, Y) :- female(X), sibling(Y, Z), parent(Z, X).
cousin_niece(X, Y) :- female(X), cousin(Y, Z), parent(Z, X).
cousin_aunt_niece(X, Y) :- female(X), cousin(W, Z), parent(Z, X), husband(W, Y).
nephew(X, Y) :- male(X), sibling(Y, Z), parent(Z, X).
cousin_nephew(X, Y):- male(X), cousin(Y, Z), parent(Z, X).
cousin_aunt_nephew(X, Y):- male(X), cousin(W, Z), parent(Z, X), husband(W, Y).
father_in_law(X, Y) :- male(X), wife(W, Y), parent(X, W).
father_in_law(X, Y) :- male(X), husband(W, Y), parent(X, W).
mother_in_law(X, Y) :- female(X), wife(W, Y), parent(X, W).
mother_in_law(X, Y) :- female(X), husband(W, Y), parent(X, W).
cousin(X, Y) :- parent(A, X), parent(B, Y), sibling(A, B).
maternal_uncle(X, Y) :- male(X), parent(Z, Y), sister(Z, X).
maternal_cousin_uncle(X, Y) :- male(X), parent(Z, Y), cousin(Z, X).
maternal_aunt(X, Y) :- female(X), father(Z, Y), brother(Z, X).
maternal_cousin_aunt(X, Y) :- female(X), parent(Z, Y), cousin(Z, W), husband(W, X).
paternal_uncle(X, Y) :- male(X), parent(Z, Y), brother(X, Z).
paternal_cousin_uncles(X,Y) :- male(X), parent(Z, Y), cousin(X, Z).
paternal_aunt(X, Y) :- female(X), parent(Z, Y), sister(Z, X).
son_in_law(X, Y) :- male(X), wife(W, X), parent(Y, W).
daughter_in_law(X, Y) :- female(X), husband(W, X), parent(Y, W).
grand_daughter_in_law(X, Y) :- female(X), husband(W, X), grandparent(Y, W).
grand_son_in_law(X, Y) :- male(X), wife(W, X), grandparent(Y, W).
in_laws(X, Y) :- husband(Husband, X), husband(Husband2, Y), sibling(Husband, Husband2).
great_grandfather(X, Y) :- male(X), parent(X, Z), grandparent(Z, Y).
great_grandmother(X, Y) :- female(X), parent(X, Z), grandparent(Z, Y).
son(X, Y) :- male(X), child(X, Y).
daughter(X, Y) :- female(X), child(X, Y).

% Define brother-in-law relationships
brother_in_law(X, Y) :- 
    (male(X), sibling(Sibling, X), husband(Sibling, Y)).

sister_in_law(X, Y) :-
    (female(X), sibling(Sibling, X), husband(Sibling, Y)).

% Function to find all daughters-in-law of a person
find_daughters_in_law(Person, DaughtersInLaw) :-
    setof(DIL, daughter_in_law(DIL, Person), DaughtersInLaw), !.
find_daughters_in_law(_, []).  % If no daughters-in-law are found, return an empty list.

% Function to find all aunts of a person
find_aunts(Person, Aunts) :-
    setof(Aunt, (maternal_aunt(Aunt, Person) ; paternal_aunt(Aunt, Person)), Aunts), !.
find_aunts(_, []).  % If no aunts are found, return an empty list.

% Example query to print aunts for a specific person
print_aunts(Person) :- 
    find_aunts(Person, Aunts), 
    format('Aunts of ~w: ~w~n', [Person, Aunts]).

% Function to find all uncles (both maternal and paternal) of a person
find_uncles(Person, Uncles) :- 
    setof(Uncle, (maternal_uncle(Uncle, Person) ; paternal_uncle(Uncle, Person)), Uncles).

% Example of how to print uncles for a specific person
print_uncles(Person) :- 
    find_uncles(Person, Uncles), 
    format('Uncles of ~w: ~w~n', [Person, Uncles]).
% Function to find maternal uncles of a person
find_maternal_uncles(Person, MaternalUncles) :- 
    setof(Uncle, (maternal_uncle(Uncle, Person) ; maternal_cousin_uncle(Uncle, Person)), MaternalUncles), !.
find_maternal_uncles(_, []).  % If no maternal uncles are found, return an empty list.

% Function to find paternal uncles of a person
find_paternal_uncles(Person, PaternalUncles) :- 
    setof(Uncle, (paternal_uncle(Uncle, Person) ; paternal_cousin_uncles(Uncle, Person)), PaternalUncles), !.
find_paternal_uncles(_, []).  % If no paternal uncles are found, return an empty list.

% Function to print both maternal and paternal uncles separately
print_uncles_separately(Person) :- 
    find_maternal_uncles(Person, MaternalUncles),
    format('Maternal Uncles of ~w: ~w~n', [Person, MaternalUncles]),
    find_paternal_uncles(Person, PaternalUncles),
    format('Paternal Uncles of ~w: ~w~n', [Person, PaternalUncles]).

% Find all parents of a person
find_parents(Person, Parents) :- 
    setof(P, parent(P, Person), Parents).

find_siblings(Person, Siblings) :- 
    setof(P, sibling(P, Person), Siblings).

% Find all grandparents of a person
find_grandparents(Person, Grandparents) :- 
    setof(G, grandparent(G, Person), Grandparents).

% Function to print all granddaughters and grandsons
print_grandchildren(Person) :-
    findall(G, (grandparent(Person, G), female(G)), Granddaughters),
    findall(G, (grandparent(Person, G), male(G)), Grandsons),
    format('Granddaughters of ~w: ~w~n', [Person, Granddaughters]),
    format('Grandsons of ~w: ~w~n', [Person, Grandsons]).

% Find all grandchildren of a person
find_grandchildren(Grandparent, Grandchildren) :-
    setof(Grandchild, (parent(Parent, Grandchild), parent(Grandparent, Parent)), Grandchildren).

% Find all cousins of a person
find_cousins(Person, Cousins) :- 
    setof(C, cousin(Person, C), Cousins).

% Find relation between two people
find_relation(Person1, Person2, Relation) :- 
    ( parent(Person1, Person2) -> Relation = 'parent'
    ; son(Person1, Person2) ->   Relation = 'son'
    ; daughter(Person1, Person2) ->  Relation = 'daughter'
    ; parent(Person2, Person1) -> Relation = 'child'
    ; grandfather(Person1, Person2) -> Relation = 'grandfather'
    ; grandmother(Person1, Person2) -> Relation = 'grandmother'
    ; grandparent(Person1, Person2) -> Relation = 'grandparent'
    ; wife(Person1, Person2) -> Relation = 'wife'
    ; husband(Person1, Person2) -> Relation = 'husband'
    ; grandparent(Person1, Person2) -> Relation = 'grandparent'
    ; grandparent(Person2, Person1) -> Relation = 'grandchild'
    ; great_grandfather(Person1, Person2) -> Relation = 'great-grandfather'
    ; great_grandmother(Person1, Person2) -> Relation = 'great-grandmother'
    ; great_grandfather(Person2, Person1) -> Relation = 'great-grandchild'
    ; cousin(Person1, Person2) -> Relation = 'cousin'
    ; sibling(Person1, Person2) -> Relation = 'sibling'
    ; brother(Person1, Person2) -> Relation = 'brother'
    ; sister(Person1, Person2) -> Relation = 'sister'
    ; niece(Person1, Person2) -> Relation = 'niece'
    ; nephew(Person1, Person2) -> Relation = 'nephew'
    ; cousin_niece(Person1, Person2) ->   Relation = 'niece'
    ; cousin_nephew(Person1, Person2) ->   Relation = 'nephew'
    ; cousin_aunt_niece(Person1, Person2) ->  Relation = 'niece'
    ; cousin_aunt_nephew(Person1, Person2) ->  Relation = 'nephew'
    ; maternal_uncle(Person1, Person2) -> Relation = 'maternal uncle'
    ; paternal_uncle(Person1, Person2) -> Relation = 'paternal uncle'
    ; maternal_aunt(Person1, Person2) -> Relation = 'maternal aunt'
    ; paternal_aunt(Person1, Person2) -> Relation = 'paternal aunt'
    ; maternal_cousin_uncle(Person1, Person2) -> Relation = 'maternal cousin uncle'
    ; maternal_cousin_aunt(Person1, Person2) -> Relation = 'maternal cousin aunt'
    ; brother_in_law(Person1, Person2) -> Relation = 'brother-in-law'
    ; sister_in_law(Person1, Person2) ->  Relation = 'sister-in-law'
    ; grand_daughter_in_law(Person1, Person2) ->  Relation = 'granddaughter-in-law'
    ; grand_son_in_law(Person1, Person2) ->  Relation = 'grandson-in-law'
    ; father_in_law(Person1, Person2) -> Relation = 'father-in-law'
    ; mother_in_law(Person1, Person2) -> Relation = 'mother-in-law'
    ; son_in_law(Person1, Person2) -> Relation = 'son-in-law'
    ; daughter_in_law(Person1, Person2) -> Relation = 'daughter-in-law'
    ; in_laws(Person1, Person2) -> Relation = "in_laws"
    ; Relation = 'no direct relation').
