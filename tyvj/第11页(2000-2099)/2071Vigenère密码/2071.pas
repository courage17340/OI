var
  a:string;
  b,c:ansistring;
  i,j:longint;
function f(a,b:char):char;
var
  i,j,flag:longint;
begin
  if ord(b)>=ord('a') then flag:=1 else flag:=2;
  b:=upcase(b);
  i:=ord(b)-ord(a)+1;
  i:=(i-1) mod 26+1;
  if i<=0 then i:=i+26;
  if flag=1 then f:=chr(i+ord('a')-1) else f:=chr(i+ord('A')-1);
end;
begin
  readln(a);
  for i:=1 to length(a) do a[i]:=upcase(a[i]);
  readln(b);
  c:='';
  for i:=1 to length(b) do
    c:=c+f(a[(i-1) mod length(a)+1],b[i]);
  writeln(c);
end.