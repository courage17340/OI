var
  s,t:string;
  i:longint;
function f(ch:char):char;
begin
  if ch=' ' then exit(' ');
  if ch in ['a'..'z'] then exit(s[ord(ch)-96]);
  if ch in ['A'..'Z'] then exit(upcase(s[ord(ch)-64]));
end;
begin
  readln(s);
  readln(t);
  for i:=1 to length(t) do write(f(t[i]));
  writeln;
end.