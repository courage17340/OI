label 100;
var
  s:string;
  a,b,c,x,y,z,i:longint;
function f(a,b:longint):longint;
begin
  a:=abs(a);b:=abs(b);
  if a=b then exit(a);
  if a=0 then exit(b);if b=0 then exit(a);
  exit(f(b,a mod b));
end;
procedure print(a,b,c:longint);
begin
  if c>0 then write('+');
  if c<>0 then write(c);
  writeln('=0');
end;
begin
  readln(s);a:=0;b:=0;writeln(stderr,s);
  i:=pos('=',s);dec(i);
  while s[i] in ['0'..'9','+','-'] do dec(i);
  write(copy(s,1,i));
  i:=pos('x',s);
  if i>2 then begin val(copy(s,1,i-1),a);delete(s,1,i);end;
  if i=2 then begin if s[1]='-' then a:=-1 else a:=ord(s[1])-48;delete(s,1,2);end;
  if i=1 then begin a:=1;delete(s,1,1);end;
  i:=pos('y',s);
  if i>2 then begin val(copy(s,1,i-1),b);delete(s,1,i);end;
  if i=2 then begin if s[1]='-' then b:=-1 else b:=1;delete(s,1,2);end;
  if i=1 then begin b:=1;delete(s,1,1);end;
  i:=pos('=',s);
  if i=1 then c:=0 else begin if s[1]='+' then begin dec(i);delete(s,1,1);end;val(copy(s,1,i-1),c);end;
  readln(s);writeln(stderr,s);
  delete(s,1,1);
  i:=pos(',',s);
  val(copy(s,1,i-1),x);delete(s,1,i);
  i:=pos(')',s);
  val(copy(s,1,i-1),y);
  if (a<0)or(a=0)and(b<0) then begin a:=-a;b:=-b;c:=-c;end;
  c:=-(a*x+b*y+c)-a*x-b*y;
  if (a*b=0)and(c=0) then begin if a=0 then b:=1 else a:=1;goto 100;end;
  100: print(a,b,c);
end.