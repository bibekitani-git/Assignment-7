let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    let a = List.nth sorted (len / 2 - 1) in
    let b = List.nth sorted (len / 2) in
    (float_of_int (a + b)) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

let mode lst =
  let freq_map = List.fold_left (fun acc x ->
    let count = try List.assoc x acc with Not_found -> 0 in
    (x, count + 1) :: List.remove_assoc x acc) [] lst in
  let max_freq = List.fold_left (fun acc (_, c) -> max acc c) 0 freq_map in
  List.fold_left (fun acc (x, c) -> if c = max_freq then x :: acc else acc) [] freq_map

let () =
  let data = [4; 2; 2; 8; 3; 3; 3] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode: %s\n" (String.concat ", " (List.map string_of_int (mode data)))
