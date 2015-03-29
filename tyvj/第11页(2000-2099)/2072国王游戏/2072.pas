type rec=record x,y:longint;end;  
var
  a:array[0..1000] of rec;
  b,c:array[1..5000] of longint;
  n,i,j,k,jw:longint;
  s,t:ansistring;
function max(a,b:longint):longint;
begin  
  max:=a;
  if a<b then max:=b;
end;
procedure swap(var a,b:rec);
var
  t:rec;
begin
  t:=a;a:=b;b:=t;
end;
procedure work;
var
  x,y:longint;
begin
  fillchar(b,sizeof(b),0);
  k:=5000;
  b[5000]:=1;
  t:='0';
  for i:=0 to n-1 do
    begin
      jw:=0;
      for j:=5000 downto k do
        begin
          b[j]:=b[j]*a[i].x+jw;
          jw:=b[j] div 10;
          b[j]:=b[j] mod 10;
        end;
      while jw>0 do
        begin
          dec(k);
          b[k]:=jw mod 10;
          jw:=jw div 10;
        end;
      jw:=0;
      c:=b;
      for j:=k to 5000 do
        begin
          jw:=jw*10;
          c[j]:=c[j]+jw;
          jw:=c[j] mod a[i+1].y;
          c[j]:=c[j] div a[i+1].y;
        end;
      x:=k;
      while (c[x]=0)and(x<5000) do inc(x);
      s:='';
      for j:=x to 5000 do s:=s+chr(c[j]+48);
      if (length(t)<length(s))or(length(t)=length(s))and(s>t) then t:=s;
    end;
end;
begin
  readln(n);
  for i:=0 to n do readln(a[i].x,a[i].y);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i].x*a[i].y>a[j].x*a[j].y then swap(a[i],a[j]);
  work;
  writeln(t);
end.