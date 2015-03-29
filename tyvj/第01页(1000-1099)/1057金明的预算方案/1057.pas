const
  maxn=3200;
  maxm=100;
var
  n,m,ans,i,j:longint;
  v,p,q1,q2,q:array[0..maxm] of longint;
  opt:array[0..maxn] of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  ans:=0;
  readln(n,m);
  n:=n div 10;
  fillchar(q1,sizeof(q1),0);
  fillchar(q2,sizeof(q2),0);
  for i:=1 to m do
    begin
      readln(v[i],p[i],q[i]);
      v[i]:=v[i] div 10;
      if q[i]<>0 then begin q2[q[i]]:=q1[q[i]];
      q1[q[i]]:=i;end;
    end;
  fillchar(opt,sizeof(opt),0);
  opt[0]:=1;
  for j:=1 to m do
   if q[j]=0 then
   for i:=n downto v[j] do
     begin
      if (i-v[j]>=0)then if(opt[i-v[j]]>0) then
       opt[i]:=max(opt[i],opt[i-v[j]]+v[j]*p[j]);
      if (i-v[j]-v[q1[j]]>=0) then if (opt[i-v[j]-v[q1[j]]]>0) then
       opt[i]:=max(opt[i],opt[i-v[j]-v[q1[j]]]+v[j]*p[j]+v[q1[j]]*p[q1[j]]);
      if (i-v[j]-v[q2[j]]>=0) then if(opt[i-v[j]-v[q2[j]]]>0) then
       opt[i]:=max(opt[i],opt[i-v[j]-v[q2[j]]]+v[j]*p[j]+v[q2[j]]*p[q2[j]]);
      if (i-v[j]-v[q1[j]]-v[q2[j]]>=0) then if (opt[i-v[j]-v[q1[j]]-v[q2[j]]]>0) then
       opt[i]:=max(opt[i],opt[i-v[j]-v[q1[j]]-v[q2[j]]]+v[j]*p[j]+v[q1[j]]*p[q1[j]]+v[q2[j]]*p[q2[j]]);
      ans:=max(ans,opt[i]);
     end;
  writeln((ans-1)*10);
end.