var
  f:array['a'..'z'] of char;
  s1,s2,s:string;
  n,m,i,j,p,x,y,k:longint;
  b:array[1..10000] of longint;
  pan:array[1..10000] of 0..1;
function top(x:longint):longint;
var s:longint;
begin
  s:=x;
  while b[x]<>x do x:=b[x];
  b[s]:=x;
  exit(x);
end;
begin
  fillchar(pan,sizeof(pan),0);
  readln(s1);
  readln(s2);
  for i:=1 to 26 do f[s1[i]]:=s2[i];
  readln(n,m);
  for i:=1 to n do b[i]:=i;
  for i:=1 to m do
    begin
      read(k);
      readln(s);
      while s[1]=' ' do delete(s,1,1);
      for j:=1 to length(s) do s[j]:=f[s[j]];
      p:=pos('poison',s);
      if p>0 then pan[k]:=1;
    end;
  readln(p);
  for i:=1 to p do
    begin
      readln(x,y);
      x:=top(x);
      y:=top(y);
      if x<>y then b[x]:=y;
    end;
  for i:=1 to n do if pan[i]=1 then pan[top(i)]:=1;
  j:=n;
  for i:=1 to n do if pan[top(i)]=1 then dec(j);
  writeln(j);
end.