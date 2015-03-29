const max=400;
var
  a:array[0..max] of double;
  i:longint;
  x:double;
function f(x:double):longint;
var
  i:longint;
begin
  for i:=1 to max do
    if a[i]>=x then exit(i);
end;
begin
  for i:=0 to max do a[i]:=0;
  for i:=1 to max do a[i]:=a[i-1]+1/(i+1);
  readln(x);
  while x>0 do
    begin
      writeln(f(x),' card(s)');
      readln(x);
    end;
end.