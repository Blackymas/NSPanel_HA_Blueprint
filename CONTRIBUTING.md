# Welcome to the contributing guide <!-- omit in toc -->

Thank you for investing your time in contributing to our project! Any contribution you make could be reflected on the final solution and make lots of other users happy. :sparkles:.

Please read [GitHub/docs Code of Conduct](https://github.com/github/docs/blob/main/CODE_OF_CONDUCT.md) to keep our community approachable and respectable.

In this guide you will get an overview of the contribution workflow from opening an issue, creating a PR, reviewing, and merging the PR.

## New contributor guide

To get an overview of the project, read the [README](README.md) and play around the [Wiki pages](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki).

Here are some resources to help you get started with open source contributions:
- [GitHub flow](https://docs.github.com/en/get-started/quickstart/github-flow)
- [Collaborating with pull requests](https://docs.github.com/en/github/collaborating-with-pull-requests)


### Issues

#### Create a new issue

If you spot a problem with the blueprint, the ESPHome or the visualization in the screen, [search if an issue already exists](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues). If a related issue doesn't exist, please open a new one.

#### Solve an issue

Scan through our [existing issues](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues) to find one that interests you. As a general rule, we don’t assign issues to anyone. If you find an issue to work on, you are welcome to open a PR with a fix.

## Contributing

#### Make changes

1. Fork the repository.

2. Create a working branch based on the `dev` branch and start with your changes!

- When proposing a change, think about all users. Some thinks to remember:
 - Support both EU and US models
 - Support to translations (add new strings in English to all languages if needed, but let us know in your comments, so we can ask the community to help with the translations)
 - Avoid breaking changes (anything changing the current behaviour) and document when you cannot avoid it. Let us know, so we can add to the release notes.

### Commit your update

Commit the changes once you are happy with them. Don't forget to self review to speed up the review process:zap:.

### Pull Request

When you're finished with the changes, create a pull request, also known as a PR.
- Make sure your pull request is using the `dev` branch as the base branch. PRs to the `main` branch will be rejected.
- Provide detailed information about what you are trying to change, why you want to change that, any breaking change, translations needed, etc.
- Don't forget to [link PR to issue](https://docs.github.com/en/issues/tracking-your-work-with-issues/linking-a-pull-request-to-an-issue) if you are solving one.
- Enable the checkbox to [allow maintainer edits](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/allowing-changes-to-a-pull-request-branch-created-from-a-fork) so the branch can be updated for a merge.
Once you submit your PR, a team member will review your proposal. We may ask questions or request additional information.
- We may ask for changes to be made before a PR can be merged, either using [suggested changes](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/incorporating-feedback-in-your-pull-request) or pull request comments. You can apply suggested changes directly through the UI. You can make any other changes in your fork, then commit them to your branch.
- As you update your PR and apply changes, mark each conversation as [resolved](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/commenting-on-a-pull-request#resolving-conversations).
- If you run into any merge issues, checkout this [git tutorial](https://github.com/skills/resolve-merge-conflicts) to help you resolve merge conflicts and other issues.

### Your PR is merged!

Congratulations :tada::tada: The community thanks you :sparkles:.

Once your PR is merged, your contributions will be publicly visible.

And welcome to the Lovelace Horizon Card contributors community!
