var
 n,i,j,ans:longint;
 s:array[1..2000] of string;
 f:array[1..2000] of longint;
begin
 readln(n);
 for i:=1 to n do readln(s[i]);
 for i:=1 to n do f[i]:=1;
 for i:=2 to n do
  for j:=1 to i-1 do
   if (pos(s[j],s[i])=1)and(f[j]+1>f[i]) then f[i]:=f[j]+1;
 ans:=0;
 for i:=1 to n do
  if ans<f[i] then ans:=f[i];
 writeln(ans);
end.