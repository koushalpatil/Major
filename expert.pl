
//expert
% Declare dynamic predicates so they can be modified during execution.
:- dynamic rating/2.
:- dynamic comment/2.
:- dynamic qualification/2.

% Facts: Define possible ratings and their corresponding scores.
rating_score(excellent, 3).
rating_score(good, 2).
rating_score(poor, 1).

% Define weights for each criterion.
weight(attendance, 3).
weight(work_efficiency, 3).
weight(adaptability, 2).
weight(creativity, 2).
weight(dependability, 2).
weight(client_interaction, 1).
weight(qualification, 5). % Weight for qualification
weight(work_experience, 3). % Weight for work experience
weight(last_year_hike, 2). % Weight for last year hike
weight(role_skills, 5). % Weight for role-specific skills

% Qualification weights
qualification_score(bachelor, 1).
qualification_score(masters, 2).
qualification_score(mba, 2).
qualification_score(mtech, 3).
qualification_score(phd, 4).

% Function to read valid input for ratings
read_rating(Criterion, Rating) :-
    format('Rate ~w (excellent, good, poor): ', [Criterion]),
    read_line_to_string(user_input, RatingStr),
    (   member(RatingStr, ["excellent", "good", "poor"])
    ->  atom_string(Rating, RatingStr)  % Convert the string to an atom
    ;   write('Invalid input. Please enter excellent, good, or poor.'), nl,
        read_rating(Criterion, Rating)
    ).

% Function to read comments for each rating
read_comment(Criterion, Comment) :-
    format('Enter comments for ~w rating: ', [Criterion]),
    read_line_to_string(user_input, Comment).

% Function to read valid qualification input
read_qualification(Q) :-
    write('Enter qualification (bachelor, masters, mba, mtech, phd): '),
    read_line_to_string(user_input, QualificationStr),
    (   member(QualificationStr, ["bachelor", "masters", "mba", "mtech", "phd"])
    ->  atom_string(Q, QualificationStr)  % Convert the string to an atom
    ;   write('Invalid input. Please enter a valid qualification.'), nl,
        read_qualification(Q)
    ).

% Function to read work experience
read_work_experience(Experience) :-
    write('Enter work experience (in years): '),
    read(Experience).

% Function to read the last year hike
read_last_year_hike(Hike) :-
    write('Enter last year hike percentage: '),
    read(Hike).

% Function to read the role
read_role(Role) :-
    write('Enter your current role (software_developer, marketing, product_manager, finance): '),
    read_line_to_string(user_input, RoleStr),
    (   member(RoleStr, ["software_developer", "marketing", "product_manager", "finance"])
    ->  atom_string(Role, RoleStr)  % Convert the string to an atom
    ;   write('Invalid input. Please enter a valid role.'), nl,
        read_role(Role)
    ).

% Function to read skills for the current role
read_skills(Role, TotalSkills) :-
    (   Role = software_developer ->
        write('Enter the skills you possess (separated by commas) from: Data structures and algorithms, Problem-solving, Understanding of technology trends, Mathematical aptitude, web development, data science: '),
        read_line_to_string(user_input, SkillsStr),
        split_string(SkillsStr, ", ", "", Skills),
        findall(Score, (member(Skill, Skills),
                        member(Skill, ["Data structures and algorithms", "Problem-solving", "Understanding of technology trends", "Mathematical aptitude", "web development", "data science"]),
                        Score = 1), DeveloperSkills),
        length(DeveloperSkills, SkillCount),
        calculate_skill_score(SkillCount, TotalSkills)
    ;   Role = marketing ->
        write('Enter the skills you possess (separated by commas) from: Market research, Digital marketing, Content creation, SEO, Communication: '),
        read_line_to_string(user_input, SkillsStr),
        split_string(SkillsStr, ", ", "", Skills),
        findall(Score, (member(Skill, Skills),
                        member(Skill, ["Market research", "Digital marketing", "Content creation", "SEO", "Communication"]),
                        Score = 1), MarketingSkills),
        length(MarketingSkills, SkillCount),
        calculate_skill_score(SkillCount, TotalSkills)
    ;   Role = product_manager ->
        write('Enter the skills you possess (separated by commas) from: Product strategy, User research, Data analysis, Roadmap planning, Communication: '),
        read_line_to_string(user_input, SkillsStr),
        split_string(SkillsStr, ", ", "", Skills),
        findall(Score, (member(Skill, Skills),
                        member(Skill, ["Product strategy", "User research", "Data analysis", "Roadmap planning", "Communication"]),
                        Score = 1), ProductSkills),
        length(ProductSkills, SkillCount),
        calculate_skill_score(SkillCount, TotalSkills)
    ;   Role = finance ->
        write('Enter the skills you possess (separated by commas) from: Financial analysis, Budgeting, Investment management, Risk assessment, Reporting: '),
        read_line_to_string(user_input, SkillsStr),
        split_string(SkillsStr, ", ", "", Skills),
        findall(Score, (member(Skill, Skills),
                        member(Skill, ["Financial analysis", "Budgeting", "Investment management", "Risk assessment", "Reporting"]),
                        Score = 1), FinanceSkills),
        length(FinanceSkills, SkillCount),
        calculate_skill_score(SkillCount, TotalSkills)
    ).

% Function to calculate the skill score based on the number of skills possessed
calculate_skill_score(SkillCount, Score) :-
    (   SkillCount >= 5 -> Score is 5
    ;   SkillCount =:= 4 -> Score is 4
    ;   SkillCount =:= 3 -> Score is 3
    ;   SkillCount =:= 2 -> Score is 2
    ;   SkillCount < 2 -> Score is 1
    ).

% Calculate total score based on ratings, weights, qualifications, work experience, hike, and role skills
calculate_total_score(TotalScore) :-
    findall(Score, (rating(Criterion, Rating), 
                    rating_score(Rating, RatingScore),
                    weight(Criterion, Weight),
                    Score is RatingScore * Weight), RatingsScores),
    
    findall(QualScore, (qualification(Qualification, Q),
                        qualification_score(Q, QualScore)), QualificationScores),
    
    % Calculate experience score directly from the asserted experience value
    findall(ExperienceScore, 
            (qualification(work_experience, Experience), 
             Weight is 3, 
             ExperienceScore is Experience * Weight), 
            ExperienceScores),

    % Calculate hike score directly from the asserted hike value
    findall(HikeScore, 
            (qualification(last_year_hike, Hike), 
             Weight is 0.5, 
             HikeScore is Hike * Weight), 
            HikeScores),

    % Calculate role skills score directly from the asserted role skills value
    findall(RoleScore, 
            (qualification(role_skills, SkillsCount), 
             Weight is 5, 
             RoleScore is SkillsCount * Weight), 
            RoleSkillsScores),

    append(RatingsScores, QualificationScores, TempScores1),
    append(TempScores1, ExperienceScores, TempScores2),
    append(TempScores2, HikeScores, TempScores3),
    append(TempScores3, RoleSkillsScores, AllScores),
    sum_list(AllScores, TotalScore).

% Evaluate based on total score
evaluate_score(Score, Outcome) :-
    (   Score >= 150 -> Outcome = promote
    ;   Score >= 130 -> Outcome = doing_well
    ;   Score >= 120 -> Outcome = needs_improvement
    ;   Outcome = training_needed
    ).

% Generate a summary report
generate_summary(RaterName, Summary) :-
    findall((Criterion, Rating, Comment), 
            (rating(Criterion, Rating), 
             comment(Criterion, Comment)), 
            Summary).

% Query to evaluate an employee
evaluate_employee :-
    write('Enter the rater name: '), 
    read_line_to_string(user_input, RaterName), % Read the rater's name
    retractall(rating(_, _)),  % Clear previous facts
    retractall(comment(_, _)),  % Clear previous comments
    retractall(qualification(_, _)),  % Clear previous qualifications

    % Collect ratings and comments for each criterion
    read_rating(attendance, A),
    read_comment(attendance, CommentA),
    assert(rating(attendance, A)),
    assert(comment(attendance, CommentA)),

    read_rating(work_efficiency, WE),
    read_comment(work_efficiency, CommentWE),
    assert(rating(work_efficiency, WE)),
    assert(comment(work_efficiency, CommentWE)),

    read_rating(adaptability, AD),
    read_comment(adaptability, CommentAD),
    assert(rating(adaptability, AD)),
    assert(comment(adaptability, CommentAD)),

    read_rating(creativity, C),
    read_comment(creativity, CommentC),
    assert(rating(creativity, C)),
    assert(comment(creativity, CommentC)),

    read_rating(dependability, D),
    read_comment(dependability, CommentD),
    assert(rating(dependability, D)),
    assert(comment(dependability, CommentD)),

    read_rating(client_interaction, CI),
    read_comment(client_interaction, CommentCI),
    assert(rating(client_interaction, CI)),
    assert(comment(client_interaction, CommentCI)),

    % Collect additional qualifications and details
    read_qualification(Q),
    assert(qualification(Q, Q)),
    
    read_work_experience(Experience),
    assert(qualification(work_experience, Experience)),
    
    read_last_year_hike(Hike),
    assert(qualification(last_year_hike, Hike)),
    
    read_role(Role),
    assert(qualification(role, Role)),
    
    read_skills(Role, SkillsCount),
    assert(qualification(role_skills, SkillsCount)),

    % Calculate total score
    calculate_total_score(TotalScore),

    % Evaluate the score
    evaluate_score(TotalScore, Outcome),

    % Generate a summary report
    generate_summary(RaterName, Summary),
    
    % Output the evaluation and summary
    write('Evaluation Outcome: '), write(Outcome), nl,
    write('Total Score: '), write(TotalScore), nl,
    write('Summary: '), write(Summary), nl.