var
  aa:array[0..200] of longint;
  v:array[0..200] of boolean;
  a,b,n,ans,i:longint;
procedure search(x,y,k:longint);
begin
  if x=b then begin if ans>k then ans:=k;exit;end;
  if k>ans then exit;
  if (y=1)and(x-aa[x]>0) then
    if v[x-aa[x]] then
      begin
        v[x-aa[x]]:=false;
        search(x-aa[x],2,k+1);
        search(x-aa[x],1,k+1);
        v[x-aa[x]]:=true;
      end;
  if (y=2)and(x+aa[x]<=n) then
    if v[x+aa[x]] then
      begin
        v[x+aa[x]]:=false;
        search(x+aa[x],2,k+1);
        search(x+aa[x],1,k+1);
        v[x+aa[x]]:=true;
      end;
end;
begin
  read(n,a,b);
  fillchar(aa,sizeof(aa),0);
  fillchar(v,sizeof(v),true);
  for i:=1 to n do read(aa[i]);
  ans:=maxlongint;
  v[a]:=false;
  search(a,1,0);search(a,2,0);
  if ans=maxlongint then ans:=-1;
  writeln(ans);
end.
