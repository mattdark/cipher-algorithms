use std::io;
static ALPHABET: [char; 26] = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];
fn main()
 {
  println!("Caesar Cipher");
  println!("1. Encrypt message");
  println!("2. Decrypt message");
  println!("Choose an option:");
  let input = io::stdin();
  let mut o = String::new();
  input.read_line(&mut o).ok().expect("Error");
  let n: Option<i32> = o.trim().parse::<i32>().ok();
  let x = match n {
            Some(x) => x,
            None            => {
                println!("Option is not valid");
                return;
            }
    };
  match x
   {
    1 => encrypt(),
    2 => decrypt(),
    _ => println!("Option is not valid"),
   }
 }
fn encrypt()
 {
  println!("Message to encrypt:");
  let input = io::stdin();
  let mut m = String::new();
  input.read_line(&mut m).ok().expect("Error");
  let value = io::stdin();
  let mut v = String::new();
  println!("Right shift:");
  value.read_line(&mut v).ok().expect("Error");
  let t: Option<i32> = v.trim().parse::<i32>().ok();
  let y = match t {
            Some(y) => y,
            None            => {
                println!("Option is not valid");
                return;
            }
    };
  let m1 = m.to_lowercase();
  let split = m1.split(" ");
  let vec: Vec<&str> = split.collect();
  let mut a;
  let s = vec.len() as usize;
  let mut xs = vec![];
  for x in 0..s
   {
    a = vec[x].chars();
    for c in a
     {
      let b = modify(c,y);
      if b!='1'
       {
        xs.push(b);
       }
     }
   }
  print!("Encrypted message is: ");
  for e in xs.iter()
   {
    print!("{}",e);
   }
 }
fn modify(c: char, y: i32) -> char
 {
  let mut c1: char = '1';
  let mut i: i32 = 0;
  let mut bool = false;
  while i < 26 && !bool
   {
    let i2 = i as usize;
    let k: char = ALPHABET[i2];
    let i3 = i+y;
    let i4 = i3 as usize;
    if c == k
     {
      bool = true;
      if i3 > 25
       {
        let r2 = i3 - 26;
        let y2 = r2 as usize;
        c1 = ALPHABET[y2];
       }
      else
       {
        c1 = ALPHABET[i4];
       }
     }
    else
     {
      bool = false;
     }
    i = i+1;
   }
  return c1;
 }
fn decrypt()
 {
  println!("Message decrypted");
 }
