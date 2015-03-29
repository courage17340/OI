var
  f:array[0..5010,0..5010] of longint;
  n,i,j:longint;
  s,t:ansistring;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  readln(n);
  readln(s);
  t:=s;
  for i:=1 to n do t[i]:=s[n+1-i];
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=1 to n do
      begin
        f[i,j]:=max(f[i,j-1],f[i-1,j]);
        if s[i]=t[j] then f[i,j]:=max(f[i,j],f[i-1,j-1]+1);
      end;
  writeln(n-f[n,n]);
end.