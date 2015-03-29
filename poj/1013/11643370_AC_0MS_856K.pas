var
  a:array[1..12] of longint;
  b:array[-1..1] of string=('light','','heavy');
  i,n,p,q:longint;
  s1,s2,s3:string;
function work(s:string):boolean;
var
  t:string;
  i,x1,x2:longint;
begin
  t:=copy(s,1,pos(' ',s)-1);
  x1:=0;x2:=0;
  for i:=1 to length(t) do x1:=x1+a[ord(t[i])-64];
  delete(s,1,pos(' ',s));
  t:=copy(s,1,pos(' ',s)-1);
  for i:=1 to length(t) do x2:=x2+a[ord(t[i])-64];
  delete(s,1,pos(' ',s));
  if (x1>x2)and(s[1]='u') then exit(true);
  if (x1<x2)and(s[1]='d') then exit(true);
  if (x1=x2)and(s[1]='e') then exit(true);
  exit(false);
end;

function yes(p,k:longint):boolean;
begin
  fillchar(a,sizeof(a),0);
  a[p]:=k;
  exit(work(s1) and work(s2) and work(s3));
end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s1);
      readln(s2);
      readln(s3);
      for p:=1 to 12 do
        for q:=-1 to 1 do if q<>0 then
          if yes(p,q) then writeln(chr(p-1+ord('A')),' is the counterfeit coin and it is ',b[q],'.');
    end;
end.