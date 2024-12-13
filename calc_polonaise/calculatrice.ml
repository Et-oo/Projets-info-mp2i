(* 1.1. Recherche du prochain esapce*)
let rec prochain_espace str i =
  if i = String.length string then i (*Si on arrive à la fin de la string alors on renvoie le dernier indice *) 
  else
    if string.[i] = ' ' then i (* si le caractère à l'indice i est un espace alors on renvoie l'indice *)
    else
      prochain_espace string (i+1) (* sinon on recommence à l'indice d'après  *)

(* 1.2 Fonction particulièrement immonde et un peu hardcodée mais elle fonctionne *)
let rec calcule_aux str index =
  let char_at_index = String.get str index in
  if char_at_index >= '0' && char_at_index <= '9' 
  then
    (* Si c'est un chiffre, construire le nombre entier *)
    let end_pos = prochain_espace str index in
    let number = int_of_string (String.sub str index (end_pos - index)) in
    (number, end_pos + 1)
  else
    (* Traitement des opérateurs +, -, * *)
    let (left_result, next_index) = calcule_aux str (index + 2) in
    let (right_result, end_index) = calcule_aux str next_index in
    let result = 
      if char_at_index = '+' then left_result + right_result
      else if char_at_index = '-' then left_result - right_result
      else if char_at_index = '*' then left_result * right_result
      else failwith "Opérateur non supporté"
    in
    (result, end_index)

(*1.3  La fonction ne marche pas, je n'arrive pas à garder une boucle qui écoute l'utilisateur sans avoir de end of line*)
let listen () =
  try
    while true do
      let line = read_line () in
      let (result, _) = calcule_aux line 0 in
      Printf.printf "Résultat: %d\n" result (* Morceau de code trouvé sur stackoverflow pour print des strings changeantes, je comprend pas trop le %d/n mais je trouve ça magique*)
    done
  with
  | End_of_file -> ()

                   



