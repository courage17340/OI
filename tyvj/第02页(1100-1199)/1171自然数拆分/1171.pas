var
  n,i,ans:longint;
  a:array[1..1000] of longint;
procedure solve(m:longint);
var
  i,j,s:longint;
begin
  ans:=ans+1;
  s:=a[m];
  for j:=a[m-1] to a[m] div 2 do
    begin
      a[m]:=j;
      a[m+1]:=s-j;
      solve(m+1);
    end;
end;
begin
  ans:=0;
  readln(n);
  for i:=1 to n div 2 do
    begin
      a[1]:=i;
      a[2]:=n-i;
      solve(2);
    end;
  writeln(ans);
end.