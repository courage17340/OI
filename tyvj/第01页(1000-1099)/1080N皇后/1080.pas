var
  a:array[1..13] of longint;
  l,x1,x2:array[-26..26] of boolean;
  n,ans:longint;
procedure search(k:longint);
var
  i:longint;
  t:boolean;
begin
  if k=n then
     begin
       t:=false;
       for i:=1 to n do if l[i] and x1[k-i] and x2[k+i] then begin t:=true;a[k]:=i;break;end;
       if t then begin inc(ans);if ans<=3 then begin for i:=1 to n-1 do write(a[i],' ');writeln(a[n]);end;end;
       exit;
     end;
  for i:=1 to n do
    if l[i] and x1[k-i] and x2[k+i] then
      begin
        l[i]:=false;x1[k-i]:=false;x2[k+i]:=false;
        a[k]:=i;
        search(k+1);
        l[i]:=true;x1[k-i]:=true;x2[k+i]:=true;
      end;
end;
begin
  read(n);
  fillchar(l,sizeof(l),true);
  fillchar(x1,sizeof(x1),true);
  fillchar(x2,sizeof(x2),true);
  search(1);
  writeln(ans);
end.