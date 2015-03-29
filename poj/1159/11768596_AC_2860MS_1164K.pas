var
  f:array[1..2,0..5010] of integer;
  n,i,j,p1,p2,tmp:longint;
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
  p1:=2;p2:=1;
  for i:=1 to n do
    begin
      tmp:=p1;p1:=p2;p2:=tmp;
      for j:=1 to n do
        begin
          f[p2,j]:=max(f[p2,j-1],f[p1,j]);
          if s[i]=t[j] then f[p2,j]:=max(f[p2,j],f[p1,j-1]+1);
      end;
    end;
  writeln(n-f[p2,n]);
end.