var
  a,b,c:array[1..200] of longint;
  n,i,j,ans,k,jw:longint;
  m:string;
function f(x:char):longint;
begin
  case x of
    '0'..'9':exit(ord(x)-48);
    'A'..'F':exit(ord(x)-ord('A')+10);
  end;
end;
procedure pan;
var
  i:longint;
begin
  for i:=k to 200 do
    if a[i]<>a[200+k-i] then exit;
  writeln('STEP=',ans);
  readln;halt;
end;
begin
  readln(n);
  readln(m);
  for i:=1 to length(m) do a[200-length(m)+i]:=f(m[i]);
  k:=200-length(m)+1;
  ans:=0;pan;
  for ans:=1 to 30 do
    begin
      for i:=k to 200 do b[i]:=a[200+k-i];
      jw:=0;
      for i:=200 downto k do
        begin
          c[i]:=a[i]+b[i]+jw;
          jw:=c[i] div n;
          c[i]:=c[i] mod n;
        end;
      while jw>0 do
        begin
          dec(k);
          c[k]:=jw mod n;
          jw:=jw div n;
        end;
      a:=c;
      pan;
    end;
  writeln('Impossible!');
  readln;
end.