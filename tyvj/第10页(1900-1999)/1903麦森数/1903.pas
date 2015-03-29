var
  a,c:array[1..500] of longint;
  b:array[1..40] of longint;
  n,i,j:longint;
procedure work1;
var
  i,j,jw:longint;
begin
  fillchar(c,sizeof(c),0);
  for i:=1 to 500 do
    for j:=1 to 500 do
      if i+j>500 then inc(c[i+j-500],a[i]*a[j]);
  jw:=0;
  for i:=500 downto 1 do
    begin
      c[i]:=c[i]+jw;
      jw:=c[i] div 10;
     c[i]:=c[i] mod 10;
    end;
  a:=c;
end;
procedure work2;
var
  i,jw:longint;
begin
  for i:=1 to 500 do a[i]:=a[i]*2;
  jw:=0;
  for i:=500 downto 1 do
    begin
      a[i]:=a[i]+jw;
      jw:=a[i] div 10;
      a[i]:=a[i] mod 10;
    end;
end;
begin
  readln(n);
  writeln(trunc(n*ln(2)/ln(10))+1);
  a[500]:=1;
  fillchar(b,sizeof(b),0);
  j:=41;
  while n>0 do
    begin
      dec(j);
      b[j]:=n mod 2;
      n:=n shr 1;
    end;
  for i:=j to 40 do
    begin
      work1;
      if b[i]=1 then work2;
    end;
  dec(a[500]);
  for i:=1 to 500 do
    begin
      write(a[i]);
      if i mod 50=0 then writeln;
    end;
end.