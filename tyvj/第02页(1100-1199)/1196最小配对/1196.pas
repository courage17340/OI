var
  a:array[1..20,1..2] of longint;
  d:array[1..20,1..20] of extended;
  v:array[1..20] of boolean;
  ans:extended;
  n,i,j:longint;
procedure search(z:extended;de:longint);
var i,j:longint;
begin
  if de=n shr 1+1 then begin if ans>z then ans:=z;exit;end;
  if z>=ans then exit;
  for i:=1 to n-1 do if not v[i] then break;
    for j:=i+1 to n do if not v[j] then
      begin
        v[i]:=true;v[j]:=true;z:=z+d[i,j];
        search(z,de+1);
        v[i]:=false;v[j]:=false;z:=z-d[i,j];
      end;
end;
begin
  read(n);fillchar(v,sizeof(v),false);
  for i:=1 to n do read(a[i,1],a[i,2]);
  for i:=1 to n do
    for j:=1 to n do
      d[i,j]:=sqrt(sqr(a[i,1]-a[j,1])+sqr(a[i,2]-a[j,2]));
  ans:=maxlongint;
  search(0,1);
  writeln(ans:0:2);
end.
