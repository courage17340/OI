var
  a,h:array[1..10] of longint;
  v:array[1..10] of boolean;
  n,i,k,ans:longint;
procedure search(x:longint);
var i:longint;
begin
  for i:=2 to n do
    if v[i] and(abs(h[i]-a[x-1])<=k) then
      begin
        if x=n then begin if abs(h[i]-a[1])<=k then inc(ans);exit;end;
        v[i]:=false;
        a[x]:=h[i];
        search(x+1);
        v[i]:=true;
      end;
end;
begin
  read(n,k);ans:=0;
  for i:=1 to n do read(h[i]);
  fillchar(v,sizeof(v),true);
  a[1]:=h[1];
  if n=1 then begin writeln(1);halt;end;
  if n=2 then begin if abs(h[1]-h[2])<=k then writeln(1) else writeln(0);halt;end;
  search(2);
  writeln(ans);
end.