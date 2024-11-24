% Defining males and females

male(janardhan).
male(babanrao).
male(bhausaheb).
male(anandrao).
male(shahajirao).
male(tanajirao).
male(abhijit).
male(ajay).
male(prakash).
male(vijay).
male(rahul).
male(sachin).
male(amol).
male(prashant).
male(sarang).
male(shailendra).
male(narayan).
male(balkrishna).
male(sagar).
male(mahadevrao).
male(ishwar).
male(avadhoot).
male(omkar).

% Defining females
female(lilabai).
female(sonabai).
female(sunanda).
female(yashoda).
female(lila).
female(alka).
female(poonam).
female(rekha).
female(surekha).
female(nanda).
female(jaldhara).
female(suchitra).
female(vandana).
female(shivlila).
female(savita).
female(shubhangi).
female(radhabai).

% Defining parent-child relationships
parent(janardhan, babanrao).
parent(sonabai, babanrao).

parent(janardhan, anandrao).
parent(sonabai, anandrao).

parent(janardhan, shahajirao).
parent(sonabai, shahajirao).

parent(janardhan, tanajirao).
parent(sonabai, tanajirao).

% Parent-child relationships of babanrao and sunanda
parent(babanrao, abhijit).
parent(sunanda, abhijit).

parent(babanrao, ajay).
parent(sunanda, ajay).

% Parent-child relationships of anandrao and yashoda
parent(anandrao, rekha).
parent(yashoda, rekha).

parent(anandrao, surekha).
parent(yashoda, surekha).

parent(anandrao, nanda).
parent(yashoda, nanda).

parent(anandrao, jaldhara).
parent(yashoda, jaldhara).

parent(anandrao, prakash).
parent(yashoda, prakash).

% Parent-child relationships of shahajirao and lila
parent(shahajirao, vijay).
parent(lila, vijay).

parent(shahajirao, rahul).
parent(lila, rahul).

parent(shahajirao, shubhangi).
parent(lila, shubhangi).

% Parent-child relationships of tanajirao and alka
parent(tanajirao, sachin).
parent(alka, sachin).

parent(tanajirao, amol).
parent(alka, amol).

% Parent-child relationships of rekha and tanaji
parent(rekha, prashant).
parent(tanaji, prashant).

parent(rekha, suchitra).
parent(tanaji, suchitra).

% New parent-child relationships
parent(surekha, sarang).
parent(kishanrao, sarang).

parent(surekha, shailendra).
parent(kishanrao, shailendra).

parent(surekha, shivlila).
parent(kishanrao, shivlila).

% New parent-child relationships
parent(nanda, narayan).
parent(vitthal, narayan).

% New parent-child relationships
parent(prakash, balkrishna).
parent(savita, balkrishna).

parent(prakash, sagar).
parent(savita, sagar).

parent(bhausaheb,mahadevrao).
parent(lilabai,mahadevrao).

% New parent-child relationships
parent(mahadevrao, savita).
parent(radhabai, savita).

parent(mahadevrao, ishwar).
parent(radhabai, ishwar).

% New parent-child relationship
parent(ishwar, omkar).


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
father_in_law(X, Y) :- male(X), wife(W, Y), parent(X, W).
father_in_law(X, Y) :- male(X), husband(W, Y), parent(X, W).
mother_in_law(X, Y) :- female(X), wife(W, Y), parent(X, W).
mother_in_law(X, Y) :- female(X), husband(W, Y), parent(X, W).
cousin(X, Y) :- parent(A, X), parent(B, Y), sibling(A, B).
maternal_uncle(X, Y) :- male(X), parent(Z, Y), sister(Z, X).
maternal_aunt(X, Y) :- female(X), parent(Z, Y), sister(X, Z).
paternal_uncle(X, Y) :- male(X), parent(Z, Y), brother(X, Z).
paternal_aunt(X, Y) :- female(X), parent(Z, Y), sister(X, Z).
son_in_law(X, Y) :- male(X), wife(W, X), parent(Y, W).
daughter_in_law(X, Y) :- female(X), husband(W, X), parent(Y, W).
great_grandfather(X, Y) :- male(X), parent(X, Z), grandparent(Z, Y).
great_great_grandfather(X, Y) :- male(X), parent(X, Z), grandparent(Z, W), parent(W, Y).
son(X, Y) :- male(X), child(X, Y).
daughter(X, Y) :- female(X), child(X, Y).

% Find parents, grandparents, cousins, and relations
find_parents(Person, Parents) :- 
    setof(P, parent(P, Person), Parents).

find_grandparents(Person, Grandparents) :- 
    setof(G, grandparent(G, Person), Grandparents).

find_cousins(Person, Cousins) :- 
    setof(C, cousin(Person, C), Cousins).

% First cousin relationship
first_cousin(X, Y) :- 
    parent(A, X), 
    parent(B, Y), 
    sibling(A, B). 

% Define second cousin relationship based on first cousins
second_cousin(X, Y) :- 
    first_cousin(A, B), 
    parent(A, X), 
    parent(B, Y). 

% Brother-in-law (husband of a person's sister)
brother_in_law(BrotherInLaw, Person) :- 
    sister(Sister, Person), 
    husband(BrotherInLaw, Sister).

sister_in_law(X, Y) :-
    ( wife(X, Z), brother(Z, Y)     % Wife of one's brother
    ; husband(Z, Y), sister(X, Z)   % Sister of one’s husband
    ; wife(Z, Y), sister(X, Z)      % Sister of one’s wife
    ).


% Uncle, aunt, nephew, and niece relationships
uncle(X, Y) :- male(X), sibling(X, Z), parent(Z, Y).
% Your mother is aunt to your father's first cousin
aunt(Mother, Cousin) :- 
    wife(Mother, Father),         % Mother is married to Father
    first_cousin(Father, Cousin). % Cousin is the first cousin of Father

nephew(X, Y) :- male(X), sibling(Y, Z), parent(Z, X).
niece(X, Y) :- female(X), sibling(Y, Z), parent(Z, X).

% Cousin uncle (your father's first cousin)
cousin_uncle(X, Y) :- 
    parent(Father, X),          % Father of X
    first_cousin(Father, Y),   % Y is the first cousin of Father
    male(Y).                    % Y must be male (cousin uncle)

cousin_aunt(X, Y) :- 
    parent(Mother, X),          % Mother of X
    first_cousin(Mother, Y),   % Y is the first cousin of Mother
    female(Y).                  % Ensure Y is female

% Cousin nephew (your father's first cousin's nephew)
cousin_child(X, Y) :-
    cousin_uncle(Y, X).  % Y is the cousin uncle of X, so X is the cousin nephew of Y


% Grandfather's sibling relations
great_uncle(X, Y) :- 
    male(X),                   % Ensure X is male
    parent(Parent, Y),         % Parent of Y
    father(Grandfather, Parent), % Grandfather of Y
    brother(X, Grandfather).    % X is a brother of Grandfather

great_aunt(X, Y) :- 
    female(X),                  % Ensure X is female
    parent(Parent, Y),         % Parent of Y
    father(Grandfather, Parent), % Grandfather of Y
    sister(X, Grandfather).     % X is a sister of Grandfather


% Your mother's cousin-in-law is your father's first cousin
cousin_in_law(Mother, Cousin) :- 
    wife(Mother, Father),         % Mother is married to Father
    first_cousin(Father, Cousin). % Cousin is the first cousin of Father



% Paternal uncle-in-law (husband of father's sister)
paternal_uncle_in_law(UncleInLaw, Person) :- 
    parent(Father, Person), 
    brother_in_law(UncleInLaw, Father).

find_relation(Person1, Person2, Relation) :- 
    ( parent(Person1, Person2) -> Relation = 'parent'  
    ; parent(Person2, Person1) -> Relation = 'child'
    ; grandparent(Person1, Person2) -> Relation = 'grandparent'
    ; grandparent(Person2, Person1) -> Relation = 'grandchild'
    ; great_grandfather(Person1, Person2) -> Relation = 'great-grandfather'
    ; great_great_grandfather(Person1, Person2) -> Relation = 'great-great-grandfather'
    ; sibling(Person1, Person2) -> Relation = 'sibling'
    ; first_cousin(Person1, Person2) -> Relation = 'first cousin'
    ; first_cousin(Person2, Person1) -> Relation = 'first cousin'
    ; second_cousin(Person1, Person2) -> Relation = 'second cousin'
    ; second_cousin(Person2, Person1) -> Relation = 'second cousin'
    ; wife(Person1, Person2) -> Relation = 'wife'
    ; husband(Person1, Person2) -> Relation = 'husband'
    ; niece(Person1, Person2) -> Relation = 'niece'
    ; nephew(Person1, Person2) -> Relation = 'nephew'
    ; uncle(Person1, Person2) -> Relation = 'uncle'
    ; aunt(Person1, Person2) -> Relation = 'aunt'
    ; aunt(Person2, Person1) -> Relation = 'cousin-in-law'
    ; cousin_uncle(Person1, Person2) -> Relation = 'cousin uncle'
    ; cousin_uncle(Person2, Person1) -> Relation = 'cousin child'
    ; cousin_aunt(Person1, Person2) -> Relation = 'cousin aunt'
    ; cousin_aunt(Person2, Person1) -> Relation = 'cousin child'
    ; mother_in_law(Person1, Person2) -> Relation = 'mother-in-law'
    ; father_in_law(Person1, Person2) -> Relation = 'father-in-law'
    ; brother_in_law(Person1, Person2) -> Relation = 'brother-in-law'
    ; sister_in_law(Person1, Person2) -> Relation = 'sister-in-law'
    ; paternal_uncle_in_law(Person1, Person2) -> Relation = 'paternal uncle-in-law'
    ; maternal_uncle(Person1, Person2) -> Relation = 'maternal uncle'
    ; paternal_aunt(Person1, Person2) -> Relation = 'paternal aunt'
    ; great_uncle(Person1, Person2) -> Relation = 'great uncle'
    ; great_uncle(Person2, Person1) -> Relation = 'great child' 
    ; great_aunt(Person1, Person2) -> Relation = 'great aunt'
    ; great_aunt(Person2, Person1) -> Relation = 'great child'
    ; cousin_in_law(Person1, Person2) -> Relation = 'cousin-in-law' % New line added
    ; Relation = 'no direct relation'
    ).
    
    
  
  % Example Queries
:- initialization(main).

% Main entry point with multiple queries
main :-
    % Test 1: Check if Prakash is a parent of Sagar
    find_relation(prakash, sagar, X),
    write('Relation : '), write(X), nl,

    % Test 2: Check if Tanajirao is the grandfather of Prashant
    find_relation(tanajirao, prashant, Y),
    write('Relation : '), write(Y), nl,

    % Test 3: Find the mother of Sagar
    mother(Mother, sagar),
    write('Mother of Sagar: '), write(Mother), nl,

    % Test 4: Find siblings of Tanajirao
    sibling(Sibling, tanajirao),
    write('Sibling of Tanajirao: '), write(Sibling), nl,

    % Test 5: Check if Amol is a nephew of Rekha
    find_relation(amol, rekha, Z),
    write('Relation : '), write(Z), nl,

    % Test 6: Find cousins of Rahul
    find_cousins(rahul, Cousins),
    write('Cousins of Rahul: '), write(Cousins), nl,

    halt. % Exit the program