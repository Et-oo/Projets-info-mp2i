(* Le code n'étant pas du tout terminé je vous enverrais une version bien plus complète par mail*)


let rec prochain_espace string i  =
  if i = String.length string then i
  else
    if string.[i] = ' ' then i
    else
      prochain_espace string (i+1)

let rec calcul_aux string i =
  String.sub string (i) ((prochain_espace string i)-2)




let armenia = calcul_aux "zefoezujfhoze+ 4 + 4 2" 2





















let egypt = prochain_espace "test test test" 0
  