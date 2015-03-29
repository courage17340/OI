var
  a,b,k,x,y,p,q,l:longint;
function work(a,b:longint):int64;
var
  d:longint;
begin
  a:=a mod b;
  d:=b-a;
  if d=1 then exit(a);
  work:=(int64(b)*int64(work(a,d))-1) div d;
end;
function gcd(a,b:longint):longint;
begin
  if b=0 then exit(a);
  exit(gcd(b,a mod b));
end;
begin
  readln(x,y,p,q,l);
  a:=p-q;
  b:=y-x;
  if a<0 then
    begin
      a:=-a;
      b:=-b;
    end;
  a:=a mod l;
  b:=b mod l;
  if b<0 then b:=b+l;
  k:=gcd(a,l);
  if b mod k<>0 then
    begin
      writeln('Impossible');
      readln;
      halt;
    end;
  a:=a div k;
  b:=b div k;
  l:=l div k;
  writeln(work(a,l)*int64(b) mod int64(l));
  readln;
end.