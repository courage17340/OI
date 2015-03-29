var
  s:ansistring;
  n,k:longint;
procedure init;
var
  i:longint;
begin
  readln(n);
  readln(s);
  k:=1;
  for i:=1 to n do k:=k*2;
end;
function panduan(s:ansistring):char;
var
  L,sum,i:longint;
begin
  L:=length(s);
  sum:=0;
  for i:=1 to L do sum:=sum+ord(s[i])-48;
  if sum=0
    then
      panduan:='B'
    else
      if sum=L
        then panduan:='I'
        else panduan:='F';
end;
procedure work(s:ansistring;t:longint);
var
  s1,s2:ansistring;
  i:longint;
begin
  if t=1
    then write(panduan(s))
    else
      begin
        i:=t div 2;
        s1:=copy(s,1,i);
        s2:=copy(s,i+1,i);
        work(s1,i);
        work(s2,i);
        write(panduan(s));
      end;
end;
begin
  init;
  work(s,k);
  writeln;
end.